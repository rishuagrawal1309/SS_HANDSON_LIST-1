#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("lockfile.txt", O_WRONLY | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          
    lock.l_pid = getpid();

    printf("Process %d: Trying to acquire write lock...\n", lock.l_pid);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("Process %d: Write lock acquired!\n", lock.l_pid);
    printf("Now writing to file...\n");

    write(fd, "This is a write lock demo.\n", 27);

    printf("Press Enter to release lock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl unlock");
        exit(1);
    }

    printf("Process %d: Lock released.\n", lock.l_pid);
    close(fd);
    return 0;
}