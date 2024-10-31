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
