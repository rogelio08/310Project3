#ifndef _graphAlgo_h
#define _graphAlgo_h 1

#include <stdio.h>
#include "node.h"


/*the following are the strucs given to us from the instruction*/
int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[]);
void dijkstraPointer(int **graph, int src, int destination, int flag, int vertxMax);
void write_pathPointer(int **graph, int src, int destination, NODE* vertexList, int savedDestination, int savedSource);
void findPointer(int **graph, int src, int destination, int flag, int vertxMax);

#endif
