/*
. Design, Develop and Implement a Program in C for the following operations on
Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using BFS
method
c. Check whether a given graph is connected or not using DFS method.Note: In the
examination each student picks one question from a lot of all the 14 questions. 
*/

#include<stdio.h>
#include<stdlib.h>

int a[10][10], n, i, j, source;
int visited[10];
void BFS(int);
void DFS(int [10][10], int, int [20], int);
void main(){
    printf("\n Enter the number of vertices of the digraph: ");
    scanf(" %d", &n);
    printf("\n Enter the adjacency matrix of the graph: \n");
    for(i = 1; i<=n ; i++){
        for(j=1; j<=n; j++){
            scanf(" %d", &a[i][j]);
        }
    }
    printf("\n Enter the source vertex to find nodes reachable or not: ");
    scanf(" %d", &source);
    BFS(source);
    for(i=1; i<=n; i++){
        if(visited[i] == 0){
            printf("\n The vertex that is not reachable is %d", i);
        }
    }
    DFS(a, source, visited, n);
    for(i=1; i<=n; i++){
        if(visited[i] == 0){
            printf("\n Graph is not connected");
            exit(0);
        }
    }
    printf("\n Graph is connected");
}

void BFS(int source){
    int q[10], u, f=0, r=-1;
    q[++r] = source;
    visited[source] = 1;
    printf("\n The reachable vertices are : ");
    while(f <= r){
        u = q[f++];
        for(i=1; i<=n; i++){
            if(a[u][i] == 1 && visited[i] == 0){
                q[++r] = i;
                visited[i] = 1;
                printf("\n %d", i);
            }
        }
    }
}

void DFS(int a[10][10], int u, int visited[10], int n){
    visited[u] = 1;
    for(i=1; i<=n; i++){
        if(a[u][i] == 1 && visited[i]==0){
            DFS(a, i, visited, n);
        }
    }
}
