#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    if (lstat(argv[1], &fileStat) < 0) {
        perror("lstat");
        return 1;
    }

    printf("File: %s\n", argv[1]);

    if (S_ISREG(fileStat.st_mode)) {
        printf("Type: Regular file\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Type: Directory\n");
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("Type: Symbolic link\n");
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("Type: Character device\n");
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("Type: Block device\n");
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("Type: FIFO (named pipe)\n");
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("Type: Socket\n");
    } else {
        printf("Type: Unknown\n");
    }

    return 0;
}

