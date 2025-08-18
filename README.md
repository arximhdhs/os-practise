# Process Information Tool

A simple C program that displays basic information about the current process.

## Features

This program displays the following process information:

- **Process IDs**: PID, PPID, PGID, SID
- **User/Group Information**: Real and effective UIDs/GIDs, username, group name
- **Current Working Directory**
- **Resource Usage Statistics**: CPU time, memory usage, page faults, context switches

## Building

To compile the program, simply run:

```bash
make
```

Or compile manually:

```bash
gcc -Wall -Wextra -std=c99 -o process_info main.c
```

## Running

After building, run the program:

```bash
make run
```

Or directly:

```bash
./process_info
```

## Sample Output

```
=== Process Information ===

Process ID (PID): 12345
Parent Process ID (PPID): 12344
Process Group ID (PGID): 12345
Session ID (SID): 12344

Real User ID (UID): 1000
Effective User ID (EUID): 1000
Real Group ID (GID): 1000
Effective Group ID (EGID): 1000

Username: user
Group name: user

Current Working Directory: /home/user/workspace/os-practise

=== Resource Usage ===
User CPU time: 0.000123 seconds
System CPU time: 0.000045 seconds
Maximum resident set size: 1024 KB
Page reclaims: 67
Page faults: 0
Voluntary context switches: 1
Involuntary context switches: 0
```

## Makefile Targets

- `make` or `make all`: Build the program
- `make run`: Build and run the program
- `make clean`: Remove compiled files
- `make install`: Install to `/usr/local/bin` (requires sudo)
- `make uninstall`: Remove from `/usr/local/bin` (requires sudo)

## System Requirements

- Unix-like operating system (Linux, macOS, etc.)
- GCC compiler
- Standard C library with POSIX extensions
