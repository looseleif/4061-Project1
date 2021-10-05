#include "main.h"

int main(int argc, char **argv)
{
	
	//Error check for number of arguments
	if (argc == 1 || argc  > 3)
	{
		printf("Incorrect number of arguments...\n");
		printf("Usage 1: ./proctree input_text_file\n");
		printf("Usage 2: ./proctree -p input_text_file\n");
		exit(1);
	}

	// mode 0 DFS
	// mode 1 parallel
	int mode;
	FILE *input;
	if (argc == 2)
	{
		mode = 0;
		input = fopen(argv[1], "r");
	}
	else if (argc == 3)
	{
		// ADDED FLEXIBILITY
		if (strcmp(argv[1], "-p")==0) //./depgraph -p input.txt
		{
			mode = 1;
			input = fopen(argv[2], "r");

		} 
		else if (strcmp(argv[2], "-p")==0) //./depgraph input.txt -p
		{
			mode = 1;
			input = fopen(argv[1], "r");
		}
		else //ERROR: the user inputed 3 arguments, but the third is something other than -p
		{
			printf("ERROR: -p not found, use -p for parallel mode...\n");
			exit(1);
		}
	}
	
	//Error checking file open
	if(!input)
	{
		printf("File %s not found...\n", argv[1]);
		printf("Exiting...\n");
		exit(1);
	}

	char cmds[32][550];
	struct DepGraph *depGraph = createDepGraph(input, cmds);

	fclose(input);

	// Used to clear the contents of output.txt for recurrent testing
	FILE* output;
	output = fopen("output.txt", "w");
	
	//Error checking file write
	if(!output)
	{
		printf("ERROR: Cannot write to %s...\n", "output.txt"); // not tested but assumed behavior
		printf("Exiting...\n");
		exit(1);
	}

	fclose(output);
	
	// For testing purposes
	// printAdjList(depGraph, cmds, mode); 

	processGraph(depGraph, cmds, mode);
	
	return 0;
}