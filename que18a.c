#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORD_SIZE sizeof(int)

int main() {
    int fd, record_num, new_value;
    int value;
    struct flock lock;

    fd = open("records.dat", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    off_t size = lseek(fd, 0, SEEK_END);
    if (size == 0) {
        int init[3] = {10, 20, 30};
        write(fd, init, sizeof(init));
        printf("Initialized file with records: 10, 20, 30\n");
    }

    printf("Enter record number to modify (0,1,2): ");
    scanf("%d", &record_num);

    printf("Enter new value: ");
    scanf("%d", &new_value);

    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE; 
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    printf("Process %d: Waiting for lock on record %d...\n", getpid(), record_num);
    fcntl(fd, F_SETLKW, &lock);
    printf("Process %d: Lock acquired on record %d\n", getpid(), record_num);

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    read(fd, &value, sizeof(int));
    printf("Old Value at record %d = %d\n", record_num, value);

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    write(fd, &new_value, sizeof(int));
    printf("New Value written at record %d = %d\n", record_num, new_value);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Record %d unlocked by process %d\n", record_num, getpid());

    close(fd);
    return 0;
}