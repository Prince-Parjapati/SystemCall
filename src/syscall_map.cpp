#include "syscall_map.hpp"
#include <sys/syscall.h>

std::map<long, std::string> init_syscall_map() {
    return {
        {SYS_read, "read"}, {SYS_write, "write"}, {SYS_open, "open"},
        {SYS_close, "close"}, {SYS_execve, "execve"}, {SYS_fork, "fork"},
        {SYS_vfork, "vfork"}, {SYS_clone, "clone"}, {SYS_exit, "exit"},
        {SYS_wait4, "wait4"}, {SYS_kill, "kill"}, {SYS_getpid, "getpid"},
        {SYS_socket, "socket"}, {SYS_connect, "connect"}, {SYS_accept, "accept"},
        {SYS_sendto, "sendto"}, {SYS_recvfrom, "recvfrom"}, {SYS_bind, "bind"},
        {SYS_listen, "listen"}, {SYS_getsockname, "getsockname"}, {SYS_shutdown, "shutdown"},
        {SYS_mmap, "mmap"}, {SYS_munmap, "munmap"}, {SYS_brk, "brk"},
        {SYS_rt_sigaction, "rt_sigaction"}, {SYS_rt_sigprocmask, "rt_sigprocmask"},
        {SYS_ioctl, "ioctl"}, {SYS_stat, "stat"}, {SYS_fstat, "fstat"},
        {SYS_lstat, "lstat"}, {SYS_unlink, "unlink"}, {SYS_dup, "dup"},
        {SYS_dup2, "dup2"}
    };
}