#pragma once

#include <string>
#include <map>

class Tracer {
public:
    Tracer(const std::string& program, char* const argv[]);
    void run();

private:
    std::string program;
    char* const* args;
    std::map<long, std::string> syscallMap;

    void trace(pid_t child);
};