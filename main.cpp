
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>
#include "node.h"
#include "util.h"
#include "graphAlgo.h"



int main(int argc, char *argv[])
{
    /* Let us create the example graph discussed above */
    

        int directed = 1;

    if (argv[2] == "undirected") {
	directed = 0;
    }

    FILE* infile, * outfile;
    int numOfVertices = 0;
    int numOfEdges = 0;
    NODE* vertecies = nullptr;
    int** graph = nullptr;
    int savedSource, savedDestination = 0;
    int printFlag = 0;
    int writeSrc, writeDest = 0;

    infile = fopen(argv[1], "r");
    if (!infile) {
        printf("Error: cannot open file for reading\n");
        
    }
    else {
        int num, numCount = 0;
        fscanf(infile, "%d", &numOfVertices);
        fscanf(infile, "%d", &numOfEdges);
        /*printf("Number of nodes: %d Number of edges: %d\n", numOfVertices, numOfEdges);*/
        numOfVertices++;

        const int Vertex = numOfVertices;

        vertecies = (NODE*)calloc(numOfVertices, sizeof(NODE));
        for (int i = 0; i < numOfVertices; i++) {
            vertecies[i].value = i;
            vertecies[i].predecessor = 0;
        }

        graph = new int* [numOfVertices];
        for (int i = 0; i < numOfVertices; i++) {
            graph[i] = new int[numOfVertices];
        }

        for (int i = 0; i < numOfVertices; i++) {
            for (int j = 0; j < numOfVertices; j++) {
                graph[i][j] = 0;
            }
        }


        int edgeNum = 0;
        int vertexIndex = 0;
        int connectingVertex = 0;
        float weight = 0.0;
        int j = 0;

        for (int i = 0; i < numOfEdges * 4; i++) {
            if (j == 4) {
                j = 0;
            }
            if (j == 0) {
                fscanf(infile, "%d", &edgeNum);
                /*printf("%d ", edgeNum);*/
            }
            if (j == 1) {
                fscanf(infile, "%d", &vertexIndex);
                /*printf("%d ", vertexIndex);*/
            }
            if (j == 2) {
                fscanf(infile, "%d", &connectingVertex);
                /*printf("%d ", connectingVertex);*/
            }
            if (j == 3) {
                fscanf(infile, "%f", &weight);
                /*printf("%d %d %d %f\n", edgeNum, vertexIndex, connectingVertex, weight);*/
                graph[vertexIndex][connectingVertex] = weight;
                if (directed == 0) {
                    graph[connectingVertex][vertexIndex] = weight;
                }
                

            }
            j++;
        }

    }

    int maxVertex = numOfVertices;


    char command = 'a';

    while (command != 's') {
        char str[30];
        /*printf("Please enter something:\n");*/
        scanf("%[^\n]%*c", str);

        command = str[0];

        switch (command)
        {
        case 'f':
            /*printf("You entered the find command\n");*/
            nextCommandFind(str, &savedSource, &savedDestination, &printFlag);
            /*printf("Source is: %d, dest is: %d, and flag is %d\n", savedSource, savedDestination, printFlag);*/
            if (savedSource == 8) {
                findPointer(graph, savedSource, savedDestination, printFlag, maxVertex);
            }
            else {
                dijkstraPointer(graph, savedSource, savedDestination, printFlag, maxVertex);
            }
            break;
        case 'w':
            /*printf("You entered the write command\n");*/
            nextCommandWrite(str, &writeSrc, &writeDest);
            /*printf("Write source: %d, write dest: %d\n", writeSrc, writeDest);*/
            write_pathPointer(graph, writeSrc, writeDest, vertecies, savedDestination, savedSource);
            break;
        case 's':
            printf("Query: stop\n");
            break;
        default:
            printf("%s is an invalid command\n", str);
            break;
        }
    }
    
    for (int i = 0; i < numOfVertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
