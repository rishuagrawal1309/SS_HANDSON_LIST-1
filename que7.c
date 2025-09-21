#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 1024  
int main() {
    int fd1, fd2, n;
    char buffer[SIZE];

    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("open file1");
        exit(1);
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open file2");
        close(fd1);
        exit(1);
    }

    while ((n = read(fd1, buffer, SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("write error");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }

    if (n < 0) {
        perror("read error");
    }

    close(fd1);
    close(fd2);

    printf("file1.txt copied to file2.txt successfully!\n");
    return 0;
}