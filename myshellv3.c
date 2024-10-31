#include <stdio.h>      // For printf, perror
#include <stdlib.h>     // For exit, NULL
#include <string.h>     // For strchr, strtok
#include <unistd.h>     // For fork, execvp, dup2, close
#include <sys/types.h>  // For pid_t
#include <sys/wait.h>   // For wait
#include <fcntl.h>      // For open, O_WRONLY, STDERR_FILENO

#define MAX_ARG_LENGTH 100  // Define a maximum argument length

void execute_command(char *cmd) {
    char *args[MAX_ARG_LENGTH];
    int background = 0;
    int i = 0;

    // Check for background process
    char *ampersand = strchr(cmd, '&');
    if (ampersand) {
        background = 1;
        *ampersand = '\0'; // Remove '&' from command
    }

    // Parse command
    char *token = strtok(cmd, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Null terminate the arguments array

    pid_t pid = fork();
    if (pid == 0) { // Child process
        if (background) {
            // Redirect stderr to /dev/null for background jobs
            int dev_null = open("/dev/null", O_WRONLY);
            if (dev_null != -1) {
                dup2(dev_null, STDERR_FILENO); // Redirect stderr to /dev/null
                close(dev_null);
            }
        }
        execvp(args[0], args); // Execute the command
        perror("execvp"); // If exec fails
        exit(1); // Exit child process
    } else if (pid > 0) { // Parent process
        if (background) {
            printf("[%d] %d\n", i, pid); // Print job number and process ID for background job
            // Do not wait for background job
        } else {
            waitpid(pid, NULL, 0); // Wait for child process to finish
        }
    } else {
        perror("fork"); // If fork fails
    }
}

int main() {
    char command[256];

    while (1) {
        printf("myshell@/home/uswah:- ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;  // Exit on EOF
        }
        command[strcspn(command, "\n")] = '\0';  // Remove newline character
        execute_command(command);
    }

    return 0;
}
