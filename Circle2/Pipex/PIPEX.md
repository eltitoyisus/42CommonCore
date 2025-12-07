# Pipex

## Description

Pipex is a project that recreates the behavior of shell pipes. You will learn about process creation, file descriptors, and inter-process communication by implementing a program that mimics the shell pipe functionality.

## Project Overview

The goal is to create a program that executes two commands connected by a pipe, similar to this shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

This project teaches you:
- Process creation with `fork()`
- File descriptor manipulation
- Pipes and inter-process communication
- The `execve()` system call
- File I/O operations
- Understanding how shell pipes work

## Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

This should behave exactly like:

```bash
< file1 cmd1 | cmd2 > file2
```

**Example:**

```bash
./pipex infile "ls -l" "wc -l" outfile
```

Should behave like:

```bash
< infile ls -l | wc -l > outfile
```

## Implementation Files

- `main.c` - Main program logic and process management
- `utils.c` - Helper functions
- `pipex.h` - Header file with function prototypes and includes
- `Makefile` - Compilation rules
- `libft/` - Your libft library (if used)

## How It Works

1. **Open files**: Open `file1` for reading and `file2` for writing
2. **Create pipe**: Create a pipe for inter-process communication
3. **Fork processes**:
   - Child process 1: Executes `cmd1`, reads from `file1`, writes to pipe
   - Child process 2: Executes `cmd2`, reads from pipe, writes to `file2`
4. **Execute commands**: Use `execve()` to execute the commands
5. **Wait and cleanup**: Parent process waits for children and handles cleanup

## Key System Calls

### Process Management
```c
fork()      // Create a new process
wait()      // Wait for child process
waitpid()   // Wait for specific child process
execve()    // Execute a program
```

### File Descriptors
```c
open()      // Open a file
close()     // Close a file descriptor
dup2()      // Duplicate file descriptor
pipe()      // Create a pipe
```

### File Operations
```c
access()    // Check file accessibility
unlink()    // Delete a file
```

## Error Handling

The program must handle:
- Invalid number of arguments
- File not found or permission errors
- Command not found
- Invalid commands
- Pipe creation failures
- Fork failures

Errors should be displayed with appropriate messages (similar to shell behavior).

## Bonus Features

### Here_doc
Support for here_doc functionality:

```bash
./pipex here_doc LIMITER cmd1 cmd2 file
```

Behaves like:

```bash
cmd1 << LIMITER | cmd2 >> file
```

### Multiple Pipes
Support for multiple commands:

```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Behaves like:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

## Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Testing Examples

```bash
./pipex infile "grep hello" "wc -l" outfile
./pipex infile "cat" "grep 42" outfile
./pipex infile "ls -l" "grep pipex" outfile
```

Compare with shell behavior:

```bash
< infile grep hello | wc -l > outfile
< infile cat | grep 42 > outfile
< infile ls -l | grep pipex > outfile
```

## Key Concepts

### Pipes
- Unidirectional communication channel
- One process writes, another reads
- Data flows in FIFO order

### Fork
- Creates child process (copy of parent)
- Returns 0 to child, child PID to parent
- Both processes continue execution

### File Descriptors
- 0: stdin (standard input)
- 1: stdout (standard output)
- 2: stderr (standard error)

### Execve
- Replaces current process with new program
- Never returns on success
- Preserves file descriptors

## Skills Acquired

- Process creation and management
- Inter-process communication
- File descriptor manipulation
- Understanding Unix pipes
- System call usage
- Error handling in system programming
- Understanding shell command execution

## Circle

**Circle 2** - System programming project at 42 School
