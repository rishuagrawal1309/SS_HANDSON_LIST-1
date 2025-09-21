#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main()
{
const char *filename = "ff.txt";
int fd = open(filename, O_RDWR|O_CREAT, 0644);
if(fd == -1)
{
perror("open");
return EXIT_FAILURE;
}
off_t offset = lseek(fd,10,SEEK_CUR);
if(offset==-1)
{
perror("lseek");
close(fd);
return EXIT_FAILURE;
}
else{
printf("lseek success. Offset: %ld\n",offset);
}
const char *data= "RRRRRRRRRR";
if(write(fd,data,10)!=10){
perror("write data");
close(fd);
return EXIT_FAILURE;
}
close(fd);
printf("data written '%s'\n",filename);
return EXIT_FAILURE;
}
