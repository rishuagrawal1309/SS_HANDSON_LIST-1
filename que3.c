#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
const char *filename = "f.txt";
int fd = creat(filename, 0600);
if(fd==-1){
perror("create");
return 1;
}
printf("file '%s' created with file descriptor %d\n", filename,fd);
close(fd);
return 0;
}
