
#include <stdio.h>
extern char **environ;

int main() {
    char **env = environ;

    printf("Environment Variables:\n\n");

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

