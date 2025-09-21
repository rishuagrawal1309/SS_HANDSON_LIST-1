#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
const char *file[5] ={ "f0.txt","f1.txt", "f2.txt","f3.txt","f4.txt"};
int fd[5];
for(int i=0;i<5;i++){
fd[i]=open(file[i], O_CREAT|O_RDWR, 0644);
if(fd[i]==-1){
perror("open");
exit(1);
}
else{
printf("opened %s with fd %d\n", file[i],fd[i]);
}
}

while(1){
sleep(10);
}

for(int i=0;i<5;i++)
{
close(fd[i]);
}
return 0;
}
