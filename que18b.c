#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORD_SIZE sizeof(int)

int main() {
    int fd, record_num, value;
    struct flock lock;

    fd = open("records.dat", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    printf("Enter record number to read (0,1,2): ");
    scanf("%d", &record_num);

    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    printf("Process %d: Waiting for read lock on record %d...\n", getpid(), record_num);
    fcntl(fd, F_SETLKW, &lock);
    printf("Process %d: Read lock acquired on record %d\n", getpid(), record_num);

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    read(fd, &value, sizeof(int));
    printf("Value at record %d = %d\n", record_num, value);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Record %d unlocked by process %d\n", record_num, getpid());

    close(fd);
    return 0;
}
