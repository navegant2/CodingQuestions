#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_dag(int **vertices, int n) {
    int i; int j;
    for (i = 1; i <= n; i++) {
        printf("%d->", i);
        for (j = 0; j < n; j++) {
            if (vertices[i][j] != 0) {
                printf(" %d ",vertices[i][j]);
            }
        }
        printf("\n");
    }
}



main() {
    int i;

    int n;
    scanf("%d", &n);

    int **vertices;
    vertices = (int **)malloc(sizeof(int *)*(n+1));
    for (i = 0; i < n+1; i++) {
        vertices[i] = (int *)malloc(sizeof(int)*n);
    }
    memset(vertices, 0, sizeof(int)*(n+1)*n);
  
    int j; 
    for (i = 1; i <= n; i++) {
        int node;
        int count;
        scanf("%d", &node);
        scanf("%d", &count);
        for (j = 0; j <= count; j++) {
            scanf("%d", &vertices[node][j]);
        }
    }
    print_dag(vertices, n);
}

    
