//plotter for dfs
#include <stdio.h>
#include <stdlib.h>

int graph[100][100], visited[100];
int op_count = 0, dfsCount = 0, count = 0;
int isCyclic = 0;

void reset(int v) 
{
    for (int i = 0; i < v; i++) 
    {
        visited[i] = 0;
    }
    op_count = dfsCount = count = 0;
    isCyclic = 0;
}

void dfs(int n, int start, int parent) 
{
    visited[start] = 1;
    count++;
    for (int i = 0; i < n; i++) 
    {
        op_count++;
        if (i != parent && graph[start][i] && visited[i])
            isCyclic = 1;
        if (graph[start][i] && visited[i] == 0)
            dfs(n, i, start);
    }
}

void plotter(int type) 
{
    FILE *f1 = fopen("dfs_b.txt", "a");
    FILE *f2 = fopen("dfs_w.txt", "a");

    for (int v = 1; v <= 10; v++) 
    {

        for (int r = 0; r < v; r++) 
        {
            for (int c = 0; c < v; c++) 
            {
                if (type == 0) 
                {  // Best case: Dense graph (Complete graph)
                    graph[r][c] = (r == c) ? 0 : 1;
                } 
                else 
                {  // Worst case: Sparse graph (Linear graph)
                    graph[r][c] = (c == r + 1) ? 1 : 0;
                }
            }
        }

        reset(v);
        dfs(v, 0, -1);
        dfsCount++;

        // Handle disconnected components
        int start = 1;
        while (count != v) 
        {
            if (visited[start] != 1) 
            {
                dfs(v, start, -1);
                dfsCount++;
            }
            start++;
        }

        if (type == 0) 
        {
            fprintf(f2, "%d\t%d\n", v, op_count);
        } else 
        {
            fprintf(f1, "%d\t%d\n", v, op_count);
        }
    }

    fclose(f1);
    fclose(f2);
}

int main() 
{
    for (int i = 0; i < 2; i++)
        plotter(i);
    printf("Data entered into the file\n");
    return 0;
}



//tester
#include<stdio.h>
#include<stdlib.h>

int visited[100], graph[100][100];
int count = 0, op_count = 0;   //count is used to caluclate number of nodes visited in each call of the dfs function
int isCyclic = 0;

void dfs(int n, int start, int parent){
    visited[start] = 1;
    count++;
    printf("-->%c ", start + 65);

    for(int i = 0; i < n; i++){
        op_count++;
        if(i != parent && graph[start][i] && visited[i])
                isCyclic = 1;
        if(graph[start][i] && visited[i] == 0)
            dfs(n, i, start);
    }
}

void main() {

    int n, dfsCount = 0; //dfsCount is used to calculate number of connected components
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("The adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nDFS traversal starting from node %c\n", 65);
    dfs(n, 0, -1);
    dfsCount++; 
    
    if (count == n)
        printf("The graph is connected\n");
    else {
        printf("The graph is not connected\n");
        int start = 1;
        while (count != n) {
            if (visited[start] != 1) {
                printf("\n");
                dfs(n, start, -1);
                dfsCount++;
            }
            start++;
        }
    }

    printf("The number of components is %d\n", dfsCount);

    if (isCyclic)
        printf("The graph is cyclic\n");
    else
        printf("The graph is not cyclic\n");
}
