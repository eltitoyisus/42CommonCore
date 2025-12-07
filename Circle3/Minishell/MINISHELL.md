# Minishell

## Description

Minishell is one of the most challenging projects in the 42 curriculum. You will create your own shell, similar to bash, capable of executing commands, handling redirections, pipes, environment variables, and built-in commands.

## Project Overview

Build a functional shell that can:
- Display a prompt and wait for user input
- Execute commands with arguments
- Handle pipes and redirections
- Manage environment variables
- Implement shell built-ins
- Handle quotes and special characters
- Process signals correctly

This project teaches you:
- Process creation and management
- Complex parsing and tokenization
- Lexical analysis and syntax validation
- Signal handling
- File descriptor manipulation
- Shell behavior and standards

## Mandatory Features

### Command Execution
- Execute commands using absolute paths, relative paths, or PATH variable
- Handle command arguments
- Preserve command history (up/down arrows)

### Quotes
- Single quotes `'` - Prevent interpretation of metacharacters
- Double quotes `"` - Prevent interpretation except for `$`

### Redirections
- `<` - Input redirection
- `>` - Output redirection (overwrite)
- `<<` - Here-doc (read until delimiter)
- `>>` - Output redirection (append)

### Pipes
- `|` - Connect output of one command to input of another
- Support multiple pipes

### Environment Variables
- `$VAR` - Expand to variable value
- `$?` - Expand to exit status of last command

### Signal Handling
- `ctrl-C` - Display new prompt (in interactive mode)
- `ctrl-D` - Exit shell
- `ctrl-\` - Do nothing (in interactive mode)

### Built-in Commands
Must implement these built-ins:
- `echo` with `-n` option
- `cd` with relative or absolute path
- `pwd` (no options)
- `export` (no options)
- `unset` (no options)
- `env` (no options)
- `exit` (no options)

## Implementation Structure

```
Minishell/
├── Makefile
├── README.md
├── includes/        # Header files
├── libft/          # Your libft library
└── src/            # Source files
    ├── builtins/   # Built-in command implementations
    ├── execution/  # Command execution logic
    ├── parsing/    # Tokenization and parsing
    ├── signals/    # Signal handlers
    └── utils/      # Utility functions
```

## Key Components

### 1. Lexer/Tokenizer
- Break input into tokens
- Identify operators, commands, arguments
- Handle quotes and escaping

### 2. Parser
- Validate syntax
- Build command structures
- Handle expansion (variables, quotes)

### 3. Executor
- Create processes for commands
- Set up pipes and redirections
- Execute built-ins vs external commands
- Handle command paths

### 4. Signal Handler
- Manage ctrl-C, ctrl-D, ctrl-\
- Different behavior for parent vs child processes

## Compilation

```bash
make        # Compile minishell
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

```bash
./minishell
```

**Example Commands:**
```bash
minishell$ echo "Hello World"
minishell$ ls -la | grep minishell
minishell$ cat < input.txt | grep pattern > output.txt
minishell$ export VAR=value
minishell$ echo $VAR
minishell$ cd ..
minishell$ pwd
minishell$ exit
```

## Parsing Examples

### Simple Command
```bash
ls -la
```

### Pipes
```bash
cat file.txt | grep pattern | wc -l
```

### Redirections
```bash
< input.txt cat | grep hello > output.txt
```

### Here-doc
```bash
cat << EOF | grep pattern
line 1
line 2
EOF
```

### Variable Expansion
```bash
echo "User: $USER, Status: $?"
```

### Quotes
```bash
echo 'Single quotes: $USER'    # Prints: Single quotes: $USER
echo "Double quotes: $USER"    # Prints: Double quotes: [username]
```

## Edge Cases to Handle

- Empty input
- Multiple spaces/tabs
- Unclosed quotes
- Invalid redirections
- Pipe at beginning/end
- Multiple consecutive pipes
- Directory as command
- Permission denied
- Command not found
- Memory leaks (use valgrind)
- Signal handling during execution

## Testing Tips

Compare behavior with bash:
```bash
# Test in bash
bash$ echo "test" | cat

# Test in your shell
minishell$ echo "test" | cat
```

Use readline library features:
- History navigation (↑↓)
- Line editing
- Auto-completion (bonus)

## Common Pitfalls

- Memory leaks in parsing/execution
- Incorrect signal handling
- Not freeing allocated memory
- Zombie processes
- File descriptor leaks
- PATH handling
- Quote parsing edge cases
- Environment variable expansion

## External Functions Allowed

- `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`
- `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`
- `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`
- `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`
- `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`
- `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

## Skills Acquired

- Shell internals and behavior
- Complex parsing and tokenization
- Process management at scale
- Signal handling in complex programs
- File descriptor juggling
- Collaborative programming
- Large-scale project organization
- Debugging complex systems
- Understanding Unix/Linux shell

## Circle

**Circle 3** - Major collaborative project at 42 School
