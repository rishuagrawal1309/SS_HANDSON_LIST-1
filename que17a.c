
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("ticket.txt", "w");
    if (fp == NULL) {
        perror("Error creating ticket file");
        return 1;
    }

    int ticket_no = 100;
    fprintf(fp, "%d\n", ticket_no);
    fclose(fp);

    printf("Ticket file initialized with ticket number %d\n", ticket_no);
    return 0;
}

