#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child (PID=%d) exiting...\n", getpid());
        _exit(0);  
    }
    else {
        printf("Parent (PID=%d) sleeping... create zombie\n", getpid());
        printf("Child PID = %d\n", pid);

        sleep(30);  
        printf("Parent exiting...\n");
    }

    return 0;
}
