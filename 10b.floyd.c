
#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 40 
int graph[MAX][MAX], n, count = 0; 
 
void createGraph() { 
    printf("Number of vertices>> "); 
    scanf("%d", &n); 
    printf("Enter adjacency matrix:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &graph[i][j]); 
        } 
    } 
} 
 
void floydWarshall() { 
    int temp; 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            temp = graph[i][k]; 
            for (int j = 0; j < n; j++) { 
                if (graph[i][j] > temp) { 
                    count++; 
                    if (temp + graph[k][j] < graph[i][j]) 
                        graph[i][j] = temp + graph[k][j]; 
                } 
            } 
        } 
    } 
} 
 
void printMatrix() { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            printf("%d ", graph[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void tester() { 
    createGraph(); 
    floydWarshall(); 
    printf("Applying Floyd's algorithm\n"); 
    printf("All pair shortest path matrix:\n"); 
    printMatrix(); 
    printf("Operation count: %d\n", count); 
} 
 
void createRandomGraph(int size) { 
    n = size; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (i == j) graph[i][j] = 0; 
            else graph[i][j] = rand() % 100; // Random weight between 0 and 99 
        } 
    } 
} 
 
void plotter() { 
    FILE *fp = fopen("floyd_general.txt", "w"); 
    for (n = 2; n < 12; n++) { 
        count = 0; 
        createRandomGraph(n); 
        floydWarshall(); 
        fprintf(fp, "%d\t%d\n", n, count); 
    } 
    fclose(fp); 
    printf("The data for plotting has been written to 'floyd_general.txt'\n"); 
} 
 
int main() { 
    int choice; 
    printf("Select mode: 1 for Tester, 2 for Plotter>> "); 
    scanf("%d", &choice); 
    switch (choice) { 
        case 1: 
            tester(); 
            break; 
        case 2: 
            plotter(); 
            break; 
        default: 
            printf("Invalid choice\n"); 
            break; 
    } 
    return 0; 
}
