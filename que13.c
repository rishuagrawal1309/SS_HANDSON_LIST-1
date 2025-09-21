#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int retval;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for up to 10 seconds...\n");
    fflush(stdout);
    retval = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
        return 1;
    } else if (retval == 0) {
        printf("⏱️  Timeout: No data was entered within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            char buffer[1024];
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                printf("✅ Data received: %s", buffer);
            } else {
                printf("⚠️  Error reading input.\n");
            }
        }
    }

    return 0;
}


