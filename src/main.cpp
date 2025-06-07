#include "tracer.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <program> [args...]\n";
        return 1;
    }

    Tracer tracer(argv[1], &argv[1]);
    tracer.run();

    return 0;
}