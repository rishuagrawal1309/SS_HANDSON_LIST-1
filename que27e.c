#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = {"ls", "-Rl", NULL};

    printf("Running ls -Rl using execvp\n");

    execvp("ls", argv);

    perror("execvp failed");
    return 1;
}

