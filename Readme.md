# Syscall Tracer

A Linux system call tracer that monitors and displays the system calls made by a program during execution.

## Features

- Trace all system calls made by a program
- Display system call names and their numeric identifiers
- Track process creation and termination

## Requirements

- Linux operating system
- C++ compiler with C++17 support (GCC recommended)
- CMake (version 3.10 or higher)

## Building from Source

   ```bash
   mkdir -p build
   cd build
   cmake ..
   cmake --build .
   ```

## Usage

Run the syscall tracer with the program you want to trace as an argument:

```bash
./syscall_tracer <program> [args...]
```

### Examples

Trace a simple command:
```bash
./syscall_tracer /bin/ls -la
```