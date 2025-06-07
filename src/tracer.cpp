#include "tracer.hpp"
#include "syscall_map.hpp"

#include <iostream>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>

Tracer::Tracer(const std::string& program, char* const argv[])
    : program(program), args(argv) {
    syscallMap = init_syscall_map();
}

void Tracer::run() {
    pid_t child = fork();
    if (child == 0) {
        ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
        kill(getpid(), SIGSTOP);
        execvp(args[0], args);
    } else {
        trace(child);
    }
}

void Tracer::trace(pid_t child) {
    int status;
    waitpid(child, &status, 0);
    ptrace(PTRACE_SYSCALL, child, nullptr, nullptr);

    while (true) {
        waitpid(child, &status, 0);
        if (WIFEXITED(status)) break;

        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, child, nullptr, &regs);

        long syscall = regs.orig_rax;
        if (syscallMap.count(syscall)) {
            std::cout << "Syscall: " << syscallMap[syscall]
                      << "(arg1=" << regs.rdi
                      << ", arg2=" << regs.rsi
                      << ", arg3=" << regs.rdx
                      << ")" << std::endl;
        }

        ptrace(PTRACE_SYSCALL, child, nullptr, nullptr);
    }
}