#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
char str[100];
fscanf(stdin, "%s", str);
fprintf(stdout, "Output fron std output: %s\n", str);
return 0;
}
