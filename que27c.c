#include <stdio.h>
#include <unistd.h>

extern char **environ;  

int main() {
    printf("Running ls -Rl using execle\n");

    execle("/bin/ls", "ls", "-Rl", (char *)NULL, environ);

    perror("execle failed");
    return 1;
}

