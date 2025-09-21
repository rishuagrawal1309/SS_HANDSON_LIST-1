#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    if (fork() > 0) {
        exit(0);  
    }

    setsid();
    chdir("/");
    umask(0);

    int done = 0; 

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == 14 && t->tm_min == 37 && !done) {
            system("/home/lenovo/myscript.sh");
            done = 1; 
        }

        if (t->tm_min != 37) {
            done = 0; 
        }

        sleep(1);
    }
    return 0;
}


