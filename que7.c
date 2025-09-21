#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>


int main(int arg, char *v[])
{
 if(arg!=3)
{
printf("./que7 src dest\n");
return 0;
}

const char *src_file= v[1];
const char *dest_file=v[2];
char buff[1024];
int res;

snprintf(buff, sizeof(buff), "cp %s %s", src_file, dest_file);
res = system(buff);
if(res!=0)
{
printf("error %d\n", errno);
printf("%s \n", strerror(errno));
return 0;
}
printf("file copied\n");
return 0;
}
