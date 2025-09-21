#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Running ls -Rl using execl\n");

    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("execl failed");
    return 1;
}

