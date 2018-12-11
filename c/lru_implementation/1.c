#include<stdio.h>
#include<stdlib.h>

typedef struct _cache_node {
    int page;
    int count;
} cache_node;

typedef struct _cache {
    cache_node *nodes;
    int max;
    int occupied;
    int least_used_page;
    int page_faults;
} cache;

int remove_oldest_page(cache *pages) {

    int i;
    int least_used_count = 0; 
    int index;

    for (i = 0; i < pages->max; i++) {
        if (pages->nodes[i].page != 0 && least_used_count >= pages->nodes[i].count) {
            least_used_count = pages->nodes[i].count;
            index = i;
        }
    }
    pages->nodes[index].page = 0;
    pages->nodes[index].count = 0;
    return index;
}
int put_cache_in_pages(int page_number, cache *pages) {
    
    int i;
    int available_slot = -1;

    for (i = 0; i < pages->max; i++) {
        if (pages->nodes[i].page == page_number) {
            return i;
        } else if (pages->nodes[i].page == 0) {
            available_slot = i;
        }
    }
    if (available_slot == -1) {
        available_slot = remove_oldest_page(pages);
        pages->page_faults++;
    }
    pages->nodes[available_slot].page = page_number;
    return available_slot;
}
void lru_implementation(int n, int *a, int s) {

    cache pages;
    pages.nodes = (cache_node *)malloc(sizeof(cache_node)*s);
    pages.max = s;
    pages.occupied = 0;
    pages.page_faults = 0;

    int i;
    for (i = 0; i < n; i++)  {
        int index = put_cache_in_pages(a[i], &pages);
        pages.nodes[i].count++;
       
    }
    printf("page faults:%d\n", pages.page_faults);
    for (i = 0; i < s; i++) {
        printf("%d : ", pages.nodes[i].page);
    }
    printf("\n");
}

main() {
    int n;
    scanf("%d", &n);
    int s;
    scanf("%d", &s);

    int *a;
    a = (int *)malloc(sizeof(int)*n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    lru_implementation(n, a, s);
}
