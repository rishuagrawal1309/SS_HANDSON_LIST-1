#include <stdio.h>
#include <sched.h>

int main() {
    int min_fifo, max_fifo, min_rr, max_rr;

    min_fifo = sched_get_priority_min(SCHED_FIFO);
    max_fifo = sched_get_priority_max(SCHED_FIFO);

    min_rr = sched_get_priority_min(SCHED_RR);
    max_rr = sched_get_priority_max(SCHED_RR);

    if (min_fifo == -1 || max_fifo == -1 || min_rr == -1 || max_rr == -1) {
        perror("sched_get_priority_min/max failed");
        return 1;
    }

    printf("SCHED_FIFO priority range: min = %d, max = %d\n", min_fifo, max_fifo);
    printf("SCHED_RR priority range:   min = %d, max = %d\n", min_rr, max_rr);

    return 0;
}

