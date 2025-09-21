#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pids[3];

   
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) {
         
            printf("Child %d started with PID %d\n", i + 1, getpid());
            sleep(5 + i);  
            printf("Child %d with PID %d exiting\n", i + 1, getpid());
            exit(i + 1);  
        } else {
            child_pids[i] = pid;
        }
    }

    int status;
    pid_t waited_pid = child_pids[1];
    printf("Parent waiting for child with PID %d\n", waited_pid);

    if (waitpid(waited_pid, &status, 0) == -1) {
        perror("waitpid failed");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
    } else {
        printf("Child with PID %d did not exit normally\n", waited_pid);
    }

    for (int i = 0; i < 3; i++) {
        if (child_pids[i] != waited_pid) {
            waitpid(child_pids[i], NULL, 0);
        }
    }

    printf("Parent process exiting.\n");
    return 0;
}

