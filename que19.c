#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include<sys/types.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned int hi, lo;
    __asm__ __volatile__ (
        "rdtsc" : "=a"(lo), "=d"(hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    pid_t pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken by getpid() in CPU cycles: %lu\n", end - start);

    return 0;
}

