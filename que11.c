
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
const char *filename= "ff.txt";
int fd = open(filename,O_WRONLY|O_CREAT|O_APPEND, 0644);
if(fd<0){
perror("open");
return EXIT_FAILURE;
}
int new_fd = dup(fd);
if(new_fd<0){
perror("dup");
close(fd);
return EXIT_FAILURE;
}
int fd2= dup2(fd ,10);
if(fd2 <0)
{
perror("dup2");
close(fd);
close(new_fd);
return EXIT_FAILURE;
}
int fd_fcntl = fcntl(fd , F_DUPFD,20);
if(fd_fcntl<0){
perror("fcntl");
close(fd);
close(new_fd);
close(fd2);
return EXIT_FAILURE;
}
return 0;
}
