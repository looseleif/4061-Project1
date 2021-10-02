#include "main.h"

int main(int argc, char **argv) {
	
	if (argc == 1 || argc  > 3) {
		printf("Incorrect number of arguments...\n");
		printf("Usage 1: ./proctree input_text_file\n");
		printf("Usage 2: ./proctree -p input_text_file\n");
		exit(1);
	}

	// mode 0 DFS
	// mode 1 parallel
	int mode;
	FILE *input;
	if (argc == 2) {
		mode = 0;
		input = fopen(argv[1], "r");
	} else if (argc ==3) {
		mode = 1;
		input = fopen(argv[2], "r");
	}

	
	if(!input) {
		printf("File %s not found...\n", argv[1]);
		printf("Exiting...\n");
		exit(1);
	}

	char cmds[32][550];
	struct DepGraph *depGraph = createDepGraph(input, cmds);

	fclose(input);

	
	
	

	// used to clear the contents of output.txt for recurrent testing
	FILE* output;
	output = fopen("output1.txt", "w");
	fclose(output);
	
	//printAdjList(depGraph, cmds, mode);

	processGraph(depGraph, cmds, mode);
	
	return 0;
}