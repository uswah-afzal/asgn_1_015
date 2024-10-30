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
