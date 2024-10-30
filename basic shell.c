#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    char command[1024]; // Buffer to store the command
    while (1) {
        printf("my_shell> "); // Display the prompt
        fgets(command, sizeof(command), stdin); // Get user input
        // Remove the newline character from the end
        command[strcspn(command, "\n")] = '\0';

        // Check for the "exit" command to end the shell
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Code to execute the command will go here
    }
    return 0;
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
