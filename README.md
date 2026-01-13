# Pipex

Short Description
-----------------
Pipex is a small POSIX C program that emulates shell-style piping between commands. It includes a core implementation and a bonus mode with support for multiple chained commands and a here-document. The project demonstrates low-level process, file descriptor, and execve usage with a minimal custom C utility library (libft).

Key Features
------------
- Parse command-line arguments and validate input/output files.
- Resolve executable paths using the PATH environment variable.
- Spawn child processes and connect them with pipes using dup2/fork/execve.
- Support for a bonus mode with multiple commands and here-documents.
- Memory-safe helpers and custom utility library (libft) for common string and I/O operations.

Tech Stack
----------
- Language: C (POSIX)
- Libraries: Custom libft static library ([libft/include/libft.h](libft/include/libft.h))
- Build: GNU Make (Makefile)
- Platform: Unix-like / Linux (uses fork, execve, pipe, dup2, open, access)

Architecture & Design
---------------------
- Single-process controller that creates child processes per command and connects them using pipes.
- Two main program variants:
  - Minimal (required) implementation: [src/pipex.c](src/pipex.c) with helper functions in [src/pipex_utils.c](src/pipex_utils.c). See [`ft_pipex`](src/pipex.c) and [`child_process_cmd`](src/pipex_utils.c).
  - Bonus implementation (multiple commands + here_doc): [bns/pipex_bns.c](bns/pipex_bns.c) with helpers in [bns/pipex_utils_bns.c](bns/pipex_utils_bns.c). See [`start_pipex`](bns/pipex_bns.c), [`ft_pipex_bns`](bns/pipex_bns.c) and [`child_manage`](bns/pipex_utils_bns.c).
- Argument validation and PATH resolution are handled in [src/check_arguments.c](src/check_arguments.c) and [bns/check_arguments_bns.c](bns/check_arguments_bns.c) via the function [`check_args`](src/check_arguments.c) / [`check_args`](bns/check_arguments_bns.c).
- Error handling and memory cleanup implemented in [src/free_memory.c](src/free_memory.c) and [bns/free_memory_bns.c](bns/free_memory_bns.c).

Getting Started
---------------
Prerequisites
- POSIX-compliant OS (Linux, macOS with appropriate tools)
- gcc, make, and standard build tools
- Basic shell to run the produced binaries

Installation
1. Clone or copy the repository into your workspace.
2. Build the project using the included Makefile. The project depends on the provided libft static library.

Running the project
- Build (required mode):
  ```sh
  make
  ```
  Produces binary `pipex`. See [Makefile](Makefile).

- Build bonus (multiple commands / here_doc):
  ```sh
  make bonus
  ```
  Produces binary `pipex_bonus`. See [Makefile](Makefile).

Usage
-----
Typical usage (required mode):
```sh
./pipex infile "cmd1 arg" "cmd2 arg" outfile
```
- Example: `./pipex infile "grep foo" "wc -l" outfile`

Bonus mode (here_doc):
```sh
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile
```
- Writes stdin lines until a line equal to LIMITER is read, then uses that data as input.

Notes:
- The program resolves commands against PATH using the logic in [src/check_arguments.c](src/check_arguments.c) / [bns/check_arguments_bns.c](bns/check_arguments_bns.c).
- Main entry points: [`main`](src/pipex.c) and [`main`](bns/pipex_bns.c).

What I Learned / Technical Challenges
------------------------------------
- Managing file descriptors and ensuring correct dup2/pipe lifecycle across parent/child processes.
- Correct PATH parsing and safe building of executable paths (`ft_strjoin`, `ft_split` used across check functions).
- Robust memory management across successful paths and error exits (see [`manage_error`](src/free_memory.c) and [`manage_error`](bns/free_memory_bns.c)).
- Implementing a reusable libft to remove standard library dependencies and to demonstrate low-level string handling.

Future Improvements
-------------------
- Improve command parsing to support quoted arguments and escaped spaces.
- Add unit tests for parsing and PATH resolution.
- Replace linear PATH search with caching for large command chains.
- Add CI (GitHub Actions) and static analysis (clang-tidy / cppcheck) in the pipeline.
- Provide more granular exit codes and structured logging.

Author & Contact
----------------
Author: schamizo
Contact: salvadorchamizo@gmail.com

References (key files & symbols)
--------------------------------
- Build and targets: [Makefile](Makefile)
- Core (required):
  - [src/pipex.c](src/pipex.c) — entry & [`ft_pipex`](src/pipex.c)
  - [src/pipex_utils.c](src/pipex_utils.c) — [`child_process_cmd`](src/pipex_utils.c)
  - [src/check_arguments.c](src/check_arguments.c) — [`check_args`](src/check_arguments.c)
  - [src/free_memory.c](src/free_memory.c) — [`manage_error`](src/free_memory.c)
- Bonus:
  - [bns/pipex_bns.c](bns/pipex_bns.c) — entry & [`ft_pipex_bns`](bns/pipex_bns.c), [`start_pipex`](bns/pipex_bns.c)
  - [bns/pipex_utils_bns.c](bns/pipex_utils_bns.c) — [`child_manage`](bns/pipex_utils_bns.c)
  - [bns/check_arguments_bns.c](bns/check_arguments_bns.c) — [`check_args`](bns/check_arguments_bns.c)
- Public headers:
  - [include/pipex.h](include/pipex.h)
  - [include/pipex_bns.h](include/pipex_bns.h)
- Supporting library:
  - [libft/include/libft.h](libft/include/libft.h)