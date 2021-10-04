#include "graph.h"

struct AdjListNode* newAdjListNode(int dest){ 
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 

struct DepGraph* createDepGraph(FILE *input, char cmds[][550]){
	ssize_t read;
	size_t len = 0;
	char *line = NULL;
    int V;

    // number of nodes
    read = getline(&line, &len, input);
    sscanf(line, "%d", &V);

    // skip the first blank line
    read = getline(&line, &len, input);

    int cmdIter = 0;
    int j;
	
    // Aquire Command Lines
    for(j=0;j<V;j++){
        
        read = getline(&line, &len, input);

		strcpy(cmds[cmdIter++], line);

	}

    // skip second blank line
    read = getline(&line, &len, input);

    // Graph creation
    struct DepGraph* graph =  (struct DepGraph*) malloc(sizeof(struct DepGraph)); 
    graph -> V = V;  
    graph -> array =  (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

    int i; 
    
    // Initialize Each Node Structure
    for (i = 0; i < V; ++i){

        graph->array[i].head = NULL;
        graph->array[i].visit = 0;

        // TODO: you can add corresponding cmd to each node, it depends on you
        // if you want to save them to graph, feel free to change graph.h and anything needed
        // otherwise you don't need to do anything here but you will extract
        // corresponding command from cmds in DFSVisit
    
    }

    char* holder;
    int src;
    int dest;


    // Aquire SRC and DEST values
    while((read = getline(&line, &len, input)) != -1) {

        holder = strtok(line, " ");
        
        src = atoi(holder);

        holder = strtok(NULL, " ");

        dest = atoi(holder);

        addEdge(graph, src, dest);

	}

    return graph; 
}


void addEdge(struct DepGraph* graph, int src, int dest){
    
    // TODO: add an edge to graph

    struct AdjListNode* newNode = newAdjListNode(dest);

    struct AdjListNode* current = graph->array[src].head;


    if (graph->array[src].head == NULL) {

        graph->array[src].head = newNode;

        current = graph->array[src].head;

    } else {

        while (current->next != NULL) {

            current = current->next;

        }

        current->next = newNode;

    }
	
}

void DFSVisit(struct DepGraph* graph, int node, char cmds[][550], int mode) {
    
    // start from node, iterate over its adjListNode

    struct AdjListNode* adjListNode = graph -> array[node].head;
    
    int PID;

    while(adjListNode != NULL){
        
        // TODO: fork then call DFSVisit inside child process recursively
        PID = fork();

        if (PID < 0) { // error

            printf("error in forking");

        }
        else if (PID == 0) { // child process

            //printf("hello\n");

            DFSVisit(graph, adjListNode->dest, cmds, mode); // "call DFSVisit recursively" node++ to increment the next node set? NOT SURE

        }
        else { // parent process

            // serial
            if (!mode) {
                
                // TODO: inside parent process, wait child process or not depend on mode
                wait(NULL);

            }

        }

        // TODO: go to next adjacent node
        adjListNode = adjListNode->next;

    }

    // TODO: wait child processes or not depend on mode
    if(mode){ while (wait(NULL) > 0); /*wait for all children before continuation*/ }


    // TODO: print current node command to results.txt

    FILE* output;

    output = fopen("output1.txt", "a");

    if(!output) {
		//printf("File %s not able to be written...\n", argv[1]); //TODO: replace argv[1] with output file path
		printf("Exiting...\n");
		exit(1);
	}

    fprintf(output, "%d %d %s", getpid(), getppid(), cmds[node]);

    fclose(output);

    // TODO: execute current node command

    char * commandSplit[50];

    int counter = 0;

    // "should" get echo for input6.txt
    commandSplit[0] = strtok(cmds[node], " \n\r");
    //printf("inital: %s\n", commandSplit[0]);

    // should get the rest
    while (commandSplit[counter] != NULL)
    {
        
        //printf("arguments: %s\n", commandSplit[counter]);
        counter = counter + 1;
        commandSplit[counter] = strtok(NULL, " \n\r");
        
    }

    commandSplit[counter] = NULL;

    //printf("-----\n");

            int k;

        /*for (k = 0; k < counter; k++) {

            printf("%s\n", commandSplit[k]);

        }

        printf("---\n");*/


    execvp(commandSplit[0],commandSplit);

    exit(0);
}

void processGraph(struct DepGraph* graph, char cmds[][550], int mode){
    int i;
    int child = fork();
    if (child == 0) {
	   DFSVisit(graph, 0, cmds, mode);
    }
    else {
        wait(NULL);
    }
}

void printAdjList(struct DepGraph* graph, char cmds[][550], int mode) { // THIS IS A TEST FUNCTION I MADE TO CONFIRM THE ADJLIST IS FUNCTIONAL

    struct AdjListNode *head = NULL;
    int i;
    for (i = 0; i < graph->V; i++) {

        head = graph->array[i].head;

        if (head == NULL) {

            //printf("Node %d's AdjList is Empty\n", i);

        }
        else {

            printf("AdjList of Node %d : %d", i,head->dest);

            while (head->next != NULL) {

                
                head = head->next;
                printf("->%d", head->dest);

            }

            printf("\n");

        }
    }

}
