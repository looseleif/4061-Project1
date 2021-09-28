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

	char testS[550];

	int j;
	for (j=0; j < 550; j++) {

		testS[j] = 'a';

	}
	
	FILE* fptr;

	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("error opening file\n");
		exit(1);
	}
	
	printf("%s\n", fgets(buff, 550, fptr));

	int num;

	//printf("\n%dbuff0\n%dbuff1\n", buff[0], buff[1]);

	int ones;
	int tens;

	if (buff[1] == 13) {

		ones = ((buff[0]) - 48);
		tens = 0;

	}
	else {

		ones = ((buff[1]) - 48);
		tens = ((buff[0]) - 48);

	}

	//printf("ones: %d\n", ones);
	
	//printf("tens: %d\n", tens);

	num = (ones) + ((tens) * 10);

	//printf("%d\n", num);

	int i;

	for (i=0; i < num; i++) {

		printf("%s\n", testS);


		//fgets(buff, 550, fptr)
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