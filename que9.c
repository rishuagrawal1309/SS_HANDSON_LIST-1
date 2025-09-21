#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
int main()
{
int fd;
struct stat s;
fd = open("f1.txt",O_RDONLY);
if(fd<0)
{
perror("file open failed");
return 1;
}
if(fstat(fd, &s)==0)
{
printf("inode num %lu\n",(unsigned long)s.st_ino);
printf("no. of hardlinks %lu\n", (unsigned long)s.st_nlink);
printf("uid %d\n", s.st_uid);
printf("gid %d\n", s.st_gid);
printf("file size %ld bytes\n",(long)s.st_size);
printf("block size %ld bytes\n",(long)s.st_blksize);
printf("last access time %s\n", ctime(&s.st_atime));
printf("last modification time %s\n", ctime(&s.st_mtime));
}
else
{
perror("fstat failed");
close(fd);
return 1;
}
close(fd);
return 0;
}
