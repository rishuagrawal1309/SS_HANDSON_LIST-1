#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    execl("./26a.out","e",(char*)NULL);
    return 0;
}

