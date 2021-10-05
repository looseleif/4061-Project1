depGraph: graph.o main.o
	gcc -o depGraph main.o graph.o

main.o: main.c main.h
	gcc -c main.c

graph.o: graph.c graph.h
	gcc -c graph.c

.PHONY: clean

clean:
	rm *.o results.txt depGraph