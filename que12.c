#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_mode(int flags) {
    int accessMode = flags & O_ACCMODE;

    switch (accessMode) {
        case O_RDONLY:
            printf("File opened in Read-Only mode.\n");
            break;
        case O_WRONLY:
            printf("File opened in Write-Only mode.\n");
            break;
        case O_RDWR:
            printf("File opened in Read-Write mode.\n");
            break;
        default:
            printf("Unknown file access mode.\n");
    }
    if (flags & O_APPEND) {
        printf("File is in Append mode.\n");
    }
    if (flags & O_NONBLOCK) {
        printf("File is in Non-blocking mode.\n");
    }
}

int main() {
    int fd;
    fd = open("example.txt", O_RDWR | O_APPEND);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    print_mode(flags);

    close(fd);
    return 0;
}

