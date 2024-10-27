#include <stdio.h>      // For printf, perror, etc.
#include <stdlib.h>     // For exit() and EXIT_FAILURE
#include <string.h>     // For strstr, strtok, etc.
#include <unistd.h>     // For fork(), dup2(), close(), execvp()
#include <sys/types.h>  // For pid_t
#include <sys/wait.h>   // For wait()
#include <fcntl.h>      // For open() and file control options


void execute_command(char *command) {
    char *args[64];
    int i = 0;
    int fd;

    // Check for redirection symbols
    char *input_file = strstr(command, "<");
    char *output_file = strstr(command, ">");

    // Split command into tokens
    args[i] = strtok(command, " ");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " ");
    }

    // Fork and execute command
    pid_t pid = fork();
    if (pid == 0) {
        // Handle output redirection
        if (output_file != NULL) {
            output_file = strtok(output_file, " ");
            fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO); // Redirect stdout to file
            close(fd);
        }
        // Handle input redirection
        if (input_file != NULL) {
            input_file = strtok(input_file, " ");
            fd = open(input_file, O_RDONLY);
            dup2(fd, STDIN_FILENO); // Redirect stdin to file
            close(fd);
        }

        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("my_shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("my_shell");
    } else {
        wait(NULL); // Wait for child process
    }
}
