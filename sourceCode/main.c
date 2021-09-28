#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	int number;
	char buff[550];
	
	FILE* fptr;

	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	
	printf("%s\n", fgets(buff, 550, fptr));

	int num;
	int digit1 = (int)buff[1];
	int digit2 = (int)buff[0];

	if (digit2 == ' ') {

		num = digit1 - 48;

	}
	else {

		num = (digit1-48) + ((digit2-48) * 10);

	}

	int i;

	for (i=0; i < num; i++) {

		printf("%s", fgets(buff, 550, fptr));

	}
	
	printf("\n");

	while (fgets(buff, 10, fptr)!=NULL) {

		printf("%s", buff);

	}

	fclose(fptr);

	return 0;
}

/*




*/