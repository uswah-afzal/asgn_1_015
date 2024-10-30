#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void execute_command(char *command) {
    char *args[64];  // Array to hold command and arguments
    int i = 0;

    // Split the command into arguments
    args[i] = strtok(command, " ");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " ");
    }

    // Create a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process: execute the command
        if (execvp(args[0], args) == -1) {
            perror("my_shell");  // Print error if command fails
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error in forking
        perror("my_shell");
    } else {
        // Parent process: wait for the child to complete
        wait(NULL);
    }
}
int main() {
    char command[1024];
    while (1) {
        printf("my_shell> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        execute_command(command); // Execute the parsed command
    }
    return 0;
}
