#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    
    int nice_value = getpriority(PRIO_PROCESS, 0);
    if (nice_value == -1) {
        perror("getpriority");
        return 1;
    }
    printf("Current nice value: %d\n", nice_value);
    return 0;
}

