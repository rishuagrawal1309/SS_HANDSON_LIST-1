#include <stdio.h>
#include <unistd.h>

int main() {
    	printf("Before exec: This is sample line.\n");

    	char *args[] = {"echo", "Helloo rishu!", NULL};

    	execvp(args[0], args);
	
	return 1;
}