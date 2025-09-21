// reserve_ticket.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("Error opening ticket file");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0; 
    lock.l_len = 0;     

    printf("Waiting to acquire write lock on ticket file...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error acquiring write lock");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");

    int ticket_no;
    FILE *fp = fdopen(fd, "r+");
    if (fp == NULL) {
        perror("fdopen failed");
        close(fd);
        return 1;
    }

    rewind(fp); 
    if (fscanf(fp, "%d", &ticket_no) != 1) {
        fprintf(stderr, "Failed to read ticket number.\n");
        fclose(fp);
        return 1;
    }

    printf("Current ticket number: %d\n", ticket_no);
    ticket_no++;

    rewind(fp); 
    fprintf(fp, "%d\n", ticket_no);
    fflush(fp); 

    printf("New ticket number reserved: %d\n", ticket_no);
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing lock");
    }

    fclose(fp);
    return 0;
}

