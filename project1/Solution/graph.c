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

    // skip the blank line
    read = getline(&line, &len, input);

    int cmdIter = 0;
	while((read = getline(&line, &len, input)) != -1) {
		if(strcmp(line, "\n") == 0){
			break;
		}
		// read commands
		strcpy(cmds[cmdIter++], line);
	}

    // Graph creation
    struct DepGraph* graph =  (struct DepGraph*) malloc(sizeof(struct DepGraph)); 
    graph -> V = V;  
    graph -> array =  (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

    int i; 
    for (i = 0; i < V; ++i){
        graph->array[i].head = NULL;
        graph->array[i].visit = 0;
        // TODO: you can add corresponding cmd to each node, it depends on you
        // if you want to save them to graph, feel free to change graph.h and anything needed
        // otherwise you don't need to do anything here but you will extract
        // corresponding command from cmds in DFSVisit
    }

    while((read = getline(&line, &len, input)) != -1) {
        // TODO: extract src and dest from current line
        // you may find strtok very helpful

        // TODO: add current edge to graph (src <-> dest forms an edge)

	}

    return graph; 
}


void addEdge(struct DepGraph* graph, int src, int dest){
    // TODO: add an edge to graph

}

void DFSVisit(struct DepGraph* graph, int node, char cmds[][550], int mode) {
    // start from node, iterate over its adjListNode
    struct AdjListNode* adjListNode = graph -> array[node].head;
    while(adjListNode != NULL){
        // TODO: fork then call DFSVisit inside child process recursively

        // TODO: inside parent process, wait child process or not depend on mode

        // TODO: go to next adjacent node

    }

    // TODO: wait child processes or not depend on mode


    // TODO: print current node command to results.txt


    // TODO: execute current node command

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
