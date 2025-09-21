#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(int argc, char* argv[]){
char line[1024];
if(argc != 2)
{
fprintf(stderr, "%s file\n", argv[0]);
return 0;
}
const char *file = argv[1];
FILE *fp= fopen(file, "r");
if(fp==NULL)
{
 perror("error in opening the file");
return 1;
}
while(fgets(line, sizeof(line), fp)!=NULL)
{
printf("%s", line);
}
fclose(fp);
return 0;
}
