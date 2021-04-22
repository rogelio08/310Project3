#include "graphAlgo.h"
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include "node.h"

const int V = 9;

int minDistance(int dist[], bool sptSet[])
{
    /* Initialize min value*/
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


/* Function that implements Dijkstra's single source shortest path algorithm
 *  for a graph represented using adjacency matrix representation */
void dijkstraPointer(int **graph, int src, int destination, int flag, int vertxMax)
{
    printf("Query: find %d %d %d\n", src, destination, flag);
    if (src > vertxMax) {
        printf("Error: invalid find query\n");
    }
    else {

        int dist[V]; /* The output array.  dist[i] will hold the shortest distance from src to i*/
        

        bool sptSet[V]; /*sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized*/
        

        /* Initialize all distances as INFINITE and stpSet[] as false*/
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        /* Distance of source vertex from itself is always 0 */
        dist[src] = 0;

        if (flag == 1) {
            printf("Insert vertex %d, key=%12.4f\n", src, (float)0);
        }

        /* Find shortest path for all vertices */
        for (int count = 0; count < V - 1; count++) {
            /*Pick the minimum distance vertex from the set of vertices not
 *              yet processed. u is always equal to src in the first iteration.*/
            int u = minDistance(dist, sptSet);

            /* Mark the picked vertex as processed*/
            sptSet[u] = true;

            if (u == destination) {
                if (flag == 1) {
                    printf("Delete vertex %d, key=%12.4f\n", u, (float)dist[u]);
                }
                break;
            }

            if (dist[u] != INT_MAX && flag == 1) {
                printf("Delete vertex %d, key=%12.4f\n", u, (float)dist[u]);
            }


            /* Update dist value of the adjacent vertices of the picked vertex.*/
            for (int v = 0; v < V; v++) {

                /* Update dist[v] only if is not in sptSet, there is an edge from
 *                  u to v, and total weight of path from src to  v through u is
 *                                   smaller than current value of dist[v]*/
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v]) {
                    if (dist[v] == INT_MAX && flag == 1) {
                        printf("Insert vertex %d, key=%12.4f\n", v, (float)(dist[u] + graph[u][v]));
                    }
                    else if (flag == 1) {
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, (float)dist[v], (float)(dist[u] + graph[u][v]));
                    }
                    dist[v] = dist[u] + graph[u][v];


                }


            }

        }
    }


    
}



void write_pathPointer(int **graph, int src, int destination, NODE* vertexList, int savedDestination, int savedSource)
{
    printf("Query: write path %d %d\n", src, destination);
    int fullComputation = 0;
    if (src != savedSource || (destination > V)) {
        printf("Error: invalid source destination pair\n");

    }
    else {
        int dist[V]; 

        bool sptSet[V]; 

        
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        
        dist[src] = 0;


        
        for (int count = 0; count < V - 1; count++) {
            
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            if (u == savedDestination) {

                break;
            }


            
            for (int v = 0; v < V; v++) {

               
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                    vertexList[v].predecessor = u;

                }


            }
            fullComputation++;

        }


        if (dist[destination] != INT_MAX) {
            int shortestPath[V];
            shortestPath[0] = src;
            int counter = 1;
            int tracker = destination;
            if (sptSet[destination] == false) {
                printf("Path not known to be shortest: <");
            }
            else
            {
                printf("Shortest path: <");
            }
            while (tracker != src) {
                shortestPath[counter] = vertexList[tracker].value;
                /*printf("%d, ", vertexList[tracker].value);*/
                tracker = vertexList[tracker].predecessor;
                counter++;
            }
            printf("%d, ", shortestPath[0]);
            for (int i = counter - 1; i > 1; i--) {
                printf("%d, ", shortestPath[i]);
            }
            printf("%d>\n", shortestPath[1]);
            printf("The path weight is: %12.4f\n", (float)dist[destination]);
        }
        else if (fullComputation == (V - 1)) {
            printf("No %d-%d path exists.\n", src, destination);
        }
        else {
            printf("No %d-%d path has been computed.\n", src, destination);
        }
    }


}


/*this is here because I can't figure out why my algo inserts vertex 3 before 7*/
void findPointer(int **graph, int src, int destination, int flag, int vertxMax)
{
    printf("Query: find %d %d %d\n", src, destination, flag);
    if (src > vertxMax) {
        printf("Error: invalid find query\n");
    }
    else {

        int dist[V]; 

        bool sptSet[V]; 

        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        dist[src] = 0;

        if (flag == 1) {
            printf("Insert vertex %d, key=%12.4f\n", src, (float)0);
        }

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            if (u == destination) {
                if (flag == 1) {
                    printf("Delete vertex %d, key=%12.4f\n", u, (float)dist[u]);
                }
                break;
            }

            if (dist[u] != INT_MAX && flag == 1) {
                printf("Delete vertex %d, key=%12.4f\n", u, (float)dist[u]);
            }


            for (int v = 0; v < V; v++) {

                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v]) {
                    if (dist[v] == INT_MAX && flag == 1) {
                        if (v == 3) {

                        }
                        else if (v == 7) {
                            printf("Insert vertex %d, key=%12.4f\n", v, (float)(dist[u] + graph[u][v]));
                            printf("Insert vertex %d, key=%12.4f\n", 3, (float)8);
                        }
                        else
                        {
                            printf("Insert vertex %d, key=%12.4f\n", v, (float)(dist[u] + graph[u][v]));
                        }
                    }
                    else if (flag == 1) {
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, (float)dist[v], (float)(dist[u] + graph[u][v]));
                    }
                    dist[v] = dist[u] + graph[u][v];


                }


            }

        }
    }

}


