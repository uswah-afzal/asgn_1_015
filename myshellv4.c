#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define HISTORY_SIZE 10

// Global array to store command history
char *history[HISTORY_SIZE];
int history_count = 0;

// Function to add command to history
void add_to_history(const char *command) {
    // Free the oldest command if history is full
    if (history_count == HISTORY_SIZE) {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history_count--;
    }
    // Add new command
    history[history_count++] = strdup(command);
}

// Function to execute a command from history
void execute_history_command(int index) {
    if (index < 0 || index >= history_count) {
        printf("No such command in history.\n");
        return;
    }
    printf("Repeating command: %s\n", history[index]);
    system(history[index]);  // Replace with actual execution code if needed
}

// Main shell loop
int main() {
    char *input;
    while (1) {
        input = readline("myshell> ");
        
        if (input == NULL) {
            printf("\n");
            break;  // Exit on EOF
        }
        
        if (strlen(input) > 0) {
            add_history(input);  // Add to readline's history
            add_to_history(input);  // Add to custom history

            // Check if input is a history command
            if (input[0] == '!') {
                int index;
                if (input[1] == '-') {
                    index = history_count - 1;  // !-1 repeats last command
                } else {
                    index = atoi(&input[1]) - 1;  // !n repeats nth command
                }
                execute_history_command(index);
            } else {
                // Regular command execution
                pid_t pid = fork();
                if (pid == 0) {
                    execlp(input, input, NULL);  // Execute the command
                    perror("Execution failed");
                    exit(1);
                } else {
                    waitpid(pid, NULL, 0);  // Parent waits for the child
                }
            }
        }
        free(input);
    }

    // Free allocated history
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
    return 0;
}
