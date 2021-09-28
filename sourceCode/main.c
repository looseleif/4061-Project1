#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {

	struct stat fileStat;
	stat("input", &fileStat);
	int fileSize = fileStat.st_size;

	int in = open(argv[1], O_RDONLY);

	char* buffer = malloc(fileSize);
	read(in, buffer, fileSize);
	close(in);
	int out = open(argv[2], O_WRONLY);
	write(out, buffer, fileSize);
	close(out);
	free(buffer);

	return 0;

}