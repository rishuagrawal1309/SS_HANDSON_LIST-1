#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("lockfile.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_RDLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          
    lock.l_pid = getpid();

    printf("Process %d: Trying to acquire read lock...\n", lock.l_pid);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("Process %d: Read lock acquired!\n", lock.l_pid);
    printf("Now reading file...\n");

    char buf[100];
    int n = read(fd, buf, sizeof(buf)-1);
    buf[n] = '\0';
    printf("File content:\n%s\n", buf);

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