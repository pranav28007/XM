
#include <stdio.h>

int a[10][10], visited[10], queue[10], front = -1, rear = -1, n;

void bfs(int v) {
    visited[v] = 1;
    queue[++rear] = v;
    if(front == -1) front = 0;

    while(front <= rear) {
        v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(a[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(0);

    return 0;
}

