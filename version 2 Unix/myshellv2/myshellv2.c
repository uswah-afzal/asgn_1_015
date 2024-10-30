#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void parse_command(char *input, char **args, int *in_fd, int *out_fd, int *pipe_flag);
void execute_command(char **args, int in_fd, int out_fd);
void execute_pipeline(char **cmd1_args, char **cmd2_args);

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    int in_fd, out_fd, pipe_flag;

    printf("uswah'shell@/home/uswah:- ");

    while (fgets(input, MAX_INPUT, stdin) != NULL) {
        input[strlen(input) - 1] = '\0';  // Remove the newline character
        
        in_fd = -1;
        out_fd = -1;
        pipe_flag = 0;
        
        parse_command(input, args, &in_fd, &out_fd, &pipe_flag);
        
        if (pipe_flag) {
            // Split commands for pipe
            char *cmd1[MAX_ARGS], *cmd2[MAX_ARGS];
            int split_index = 0;
            for (int i = 0; args[i] != NULL; i++) {
                if (strcmp(args[i], "|") == 0) {
                    split_index = i;
                    break;
                }
                cmd1[i] = args[i];
            }
            cmd1[split_index] = NULL;
            
            for (int j = split_index + 1, k = 0; args[j] != NULL; j++, k++) {
                cmd2[k] = args[j];
            }
            cmd2[split_index] = NULL;
            
            execute_pipeline(cmd1, cmd2);
        } else {
            execute_command(args, in_fd, out_fd);
        }
        
        printf("uswah'shell@/home/uswah:- ");
    }
    
    return 0;
}

void parse_command(char *input, char **args, int *in_fd, int *out_fd, int *pipe_flag) {
    int arg_index = 0;
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                *in_fd = open(token, O_RDONLY);
                if (*in_fd < 0) {
                    perror("Error opening input file");
                    exit(1);
                }
            }
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                *out_fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (*out_fd < 0) {
                    perror("Error opening output file");
                    exit(1);
                }
            }
        } else if (strcmp(token, "|") == 0) {
            *pipe_flag = 1;
            args[arg_index++] = token;
        } else {
            args[arg_index++] = token;
        }
        token = strtok(NULL, " ");
    }
    args[arg_index] = NULL;
}

void execute_command(char **args, int in_fd, int out_fd) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (in_fd != -1) {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }
        if (out_fd != -1) {
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }
        
        execvp(args[0], args);
        perror("Execution failed");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        if (in_fd != -1) close(in_fd);
        if (out_fd != -1) close(out_fd);
    }
}

void execute_pipeline(char **cmd1_args, char **cmd2_args) {
    int pipe_fd[2];
    if (pipe(pipe_fd) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }
    
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        // First child for cmd1 (writing to pipe)
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
        
        execvp(cmd1_args[0], cmd1_args);
        perror("Execution of cmd1 failed");
        exit(1);
    }
    
    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid2 == 0) {
        // Second child for cmd2 (reading from pipe)
        close(pipe_fd[1]);
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        
        execvp(cmd2_args[0], cmd2_args);
        perror("Execution of cmd2 failed");
        exit(1);
    }
    
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
