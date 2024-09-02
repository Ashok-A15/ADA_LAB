#include <stdio.h>
#include<stdlib.h>
#define n1 4
#define n2 8
int graph[20][20], visited[20], dist[20], n,cnt;
      int mindist() {
      int min = 9999, md;
      for (int i = 0; i < n; i++) {
      if (!visited[i] && dist[i] < min) {
      min = dist[i];
      md = i;
}
}
return md;
}
      void dijkstra(int v) {
      for (int i = 0; i < n; i++) {
      dist[i] = 9999;
      visited[i] = 0;
}
      dist[v] = 0;
      for (int i=0; i < n; i++) {
      int j = mindist();
      visited[j] = 1;
      for (int i = 0; i < n; i++) {
      cnt++;
      if (!visited[i] && graph[j][i] && dist[j] != 9999 &&
      dist[j] + graph[j][i] < dist[i]) {
      dist[i] = dist[j] + graph[j][i];
}
}
}
      printf("Shortest distances from source vertex %d:\n", v);
      for (int i = 0; i < n; i++)
      printf("Vertex %d: %d\n", i, dist[i]);
}
void correctness() {
      int start;
      printf("Enter the number of vertices: ");
      scanf("%d", &n);
      printf("Enter the adjacency matrix :\n");
      for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
      }
      }
      printf("Enter the source vertex: ");
      scanf("%d", &start);
      dijkstra(start);
      }
void analysis() {
        int i, j;
        FILE *f;
        f = fopen("BC15.txt", "a");
        for (n = n1; n <= n2; n += 1) {
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        if (i == j)
        graph[i][j] = 0;
        else
        graph[i][j] = rand() % 10;
        for(int i=0;i<n;i++)
        visited[i] = 0;
        cnt = 0;
        dijkstra(0);
        fprintf(f, "%d\t%d\n", n, cnt);
        }system("gnuplot>load 'command.txt'");
        fclose(f);
        }
void main() {
    int ch;
printf("1.analysis\t\t2.correctness\t\t0.exit\n");
for (;;) {
printf("enter choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
      analysis();
      break;
case 2:
      correctness();
      break;
case 0:
      printf("exiting..\n");
      exit(0);
default:
      printf("wrong choice!!\n");
break;
}
}
}
set xrange
set yrange
set xlabel 'N
set ylabel 'operation count'
set style data linespoints
plot 'BC15.txt' title 'analysis'
pause -1 'hit any way'
