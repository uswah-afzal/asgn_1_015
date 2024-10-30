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

