#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
int t[MAX][MAX], v[MAX], w[MAX], n, m, count = 0; 
 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
 
int knap(int n, int m) { 
    for (int i = 0; i < n + 1; i++) { 
        for (int j = 0; j < m + 1; j++) { 
            if (i == 0 || j == 0) 
                t[i][j] = 0; 
            else { 
                count++; 
                if (j < w[i]) 
                    t[i][j] = t[i - 1][j]; 
                else 
                    t[i][j] = max(t[i - 1][j], v[i] + t[i - 1][j - w[i]]); 
            } 
        } 
    } 
    return t[n][m]; 
} 
 
void printMatrix() { 
    for (int i = 0; i < n + 1; i++) { 
        for (int j = 0; j < m + 1; j++) { 
            printf("%d ", t[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void printComposition() { 
    printf("Composition:\n"); 
    for (int i = n; i > 0; i--) { 
        if (t[i][m] != t[i - 1][m]) { 
            printf("%d\t", i); 
            m = m - w[i]; 
        } 
    } 
    printf("\n"); 
} 
 
void tester() { 
    printf("Number of items: "); 
    scanf("%d", &n); 
    printf("Sack capacity: "); 
    scanf("%d", &m); 
    printf("Weight\tValue\n"); 
    for (int i = 1; i < n + 1; i++) { 
        scanf("%d\t%d", &w[i], &v[i]); 
    } 
    printf("Max value %d\n", knap(n, m)); 
    printMatrix(); 
    printComposition(); 
    printf("Operation count: %d\n", count); 
} 
 
void run() { 
    count = 0; 
    srand(time(0));  
    n = rand() % 20 + 1; // Random number of items between 1 and 20 
    m = rand() % 50 + 1; // Random sack capacity between 1 and 50 
 
    for (int i = 1; i < n + 1; i++) { 
        w[i] = rand() % 20 + 1; // Random weight between 1 and 20 
        v[i] = rand() % 100 + 1; // Random value between 1 and 100 
    } 
 
    knap(n, m); 
    printf("Operation count: %d\n", count); 
} 
 
void plotter() { 
    FILE *f1 = fopen("knapsackgraph.txt", "a"); 
    run(); 
    fprintf(f1, "%d\t%d\n", n, count); 
    fclose(f1); 
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
