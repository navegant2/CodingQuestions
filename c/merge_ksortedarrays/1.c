#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int get_minimum_element(int **karray, int k, int n, int *kIndex) {

    int i = 0;
    int minimum = INT_MAX;
    int array_index = 0;
    int array_kindex = 0; 

    for (i = 0; i < k; i++) {
        if (kIndex[i] < n && minimum > karray[i][kIndex[i]]) {
            minimum = karray[i][kIndex[i]];
            array_index = i;
            array_kindex = kIndex[i];
        }
    }
    kIndex[array_index]++;
    return minimum;
}

void merge_ksortedarrays(int **karrays, int k, int n, int *mergedList) {
    int *kIndex;
    int i, j;

    kIndex = (int *)malloc(sizeof(int)*k);
    for (i = 0; i < k; i++) {
        kIndex[i] = 0;
    }

    for (i = 0; i < k *n; i++) {
        mergedList[i] = get_minimum_element(karrays, k, n, kIndex);
    }
}
main() {

    int n;
    int **Karrays;
    int k = 0;
    int i = 0, j = 0;
    int *mergedList;

    scanf("%d", &n);
    scanf("%d", &k);
    Karrays = (int **)malloc(sizeof(int *)*k);
    for (i = 0; i < k; i++) {
        Karrays[i]= (int *)malloc(sizeof(int)*n);
    } 
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&Karrays[i][j]);
        }
    }
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ",Karrays[i][j]);
        }
        printf("\n");
    }
    mergedList = (int *)malloc(sizeof(int)*n*k);
    merge_ksortedarrays(Karrays, k, n, mergedList);
    for (i = 0; i < k*n; i++) {
        printf("%d ",mergedList[i]);
    }
    printf("\n");

}
     

    

