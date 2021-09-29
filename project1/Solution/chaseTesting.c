#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv) {

	char str[20] = "0 1";

    char* pch;

    pch = strtok(str, " ");

    int num = pch[0]-48;

    printf("%d\n", num);
    
    pch = strtok(NULL, " ");

    num = pch[0]-48;

    printf("%d\n", num);

    return 0;

}