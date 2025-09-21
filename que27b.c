#include <stdio.h>
#include <unistd.h>
#include<sched.h>
int main() {
    printf("Running ls -Rl using execlp\n");

    execlp("ls", "ls", "-Rl", (char *)NULL);

    perror("execlp failed");
    return 1;
}

