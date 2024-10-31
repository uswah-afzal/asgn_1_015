<<<<<<< HEAD
# MyShell Version 4

MyShell is a simple command-line shell implemented in C that allows users to execute commands, handle input/output redirection, support piping, maintain command history, and run commands in the background.

## Features

- **Command Execution**: Execute external commands from the shell.
- **Input/Output Redirection**: Use `<` to redirect input and `>` to redirect output.
- **Piping**: Use the pipe `|` operator to send the output of one command as input to another.
- **Command History**: Repeat previously issued commands using the `!number` syntax, where `number` refers to the command's history index.
- **Background Process Execution**: Run commands in the background using `&`.

## Requirements

- GCC (GNU Compiler Collection) or any C compiler
- `libreadline` development library (for input handling)

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/myshell.git
   cd myshell
   ```

2. **Install Dependencies** (if not already installed):
   - For Debian/Ubuntu:
     ```bash
     sudo apt-get update
     sudo apt-get install libreadline-dev
     ```

3. **Compile the Program**:
   ```bash
   gcc -o myshellv4 myshellv4.c -lreadline
   ```

## Usage

1. **Run the Shell**:
   ```bash
   ./myshellv4
   ```

2. **Entering Commands**:
   - Type any valid shell command and press `Enter`.
   - Examples:
     - `ls` - List directory contents.
     - `pwd` - Print current working directory.
     - `cat < inputfile.txt` - Display contents of a file.
     - `echo "Hello" > outputfile.txt` - Redirect output to a file.
     - `cat file.txt | grep "search_term"` - Use pipes to filter output.

3. **Command History**:
   - Repeat the last command: `!-1`
   - Repeat the first command: `!1`

4. **Background Processes**:
   - Run a command in the background: `sleep 10 &`

5. **Exit the Shell**:
   - Type `exit` to terminate the shell.

## Notes

- The shell maintains a history of the last 10 commands.
- Commands are executed in a separate process.
- Signals are handled to avoid zombie processes.

## Contributing

If you would like to contribute to MyShell, please fork the repository and create a pull request with your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
=======
<<<<<<< HEAD
# myshellv3 - Version 3

## Overview
`myshellv3` is a customized shell program that extends functionality to run commands in the background, allowing users to continue interacting with the shell while tasks execute. This version includes signal handling to prevent zombie processes, ensuring efficient process management.

## Key Features
- **Background Execution**: Users can run commands by appending an `&` at the end of the command line, enabling concurrent command execution.
- **Job Tracking**: Displays the job number and process ID (PID) for each background task, providing users with real-time updates on their running commands.
- **Signal Handling**: Properly handles signals to prevent zombie processes from accumulating, maintaining a clean and efficient process table.

## Getting Started

### run


git clone https://github.com/uswah-afzal/myshellv3.git
cd myshellv3
gcc myshellv3.c -o myshellv3
./myshellv3
### command example
find / -name f1.txt &
ls -l &

=======
# # Assignment: Shell Implementation

## Overview
This assignment involves creating a simple shell program in C. The shell allows users to execute commands, manage input and output redirection, and supports basic command-line arguments.

## Features
- Execute commands using the `execvp` function.
- Handle input and output redirection using `<` and `>` symbols.
- Support for multiple command-line arguments.
- Error handling for invalid commands and redirection issues.

## Getting Started

### Prerequisites
- Ensure you have GCC installed on your system for compiling C programs.
- A Unix-like terminal Git Bash for Windows.

### Clone the Repository
To clone the repository, run the following command in your terminal:
```bash
git clone https://github.com/uswah-afzal/asgn_1_bsdsf22m015.git
>>>>>>> 702b2d913db6cf2a23c2e555f7a5c4c3a16a51c7
>>>>>>> e542088f30cf7039a9329a15347be8e421dc0a93
