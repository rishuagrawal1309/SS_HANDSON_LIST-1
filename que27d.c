#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = {"ls", "-Rl", NULL};

    printf("Running ls -Rl using execv\n");

    execv("/bin/ls", argv);

    perror("execv failed");
    return 1;
}

