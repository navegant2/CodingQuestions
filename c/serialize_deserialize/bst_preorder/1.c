#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} Node;

main() {

    int *data;
    int len;
    scanf("%d", &len);
    int i;
    data = (int *)malloc(sizeof(int)*len);
    for (i = 0; i < len; i++) {
        scanf("%d", &data[i]);
    }
    
