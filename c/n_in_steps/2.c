#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

char *create_new(char *string, int size) {
    printf("------------(%d)\n", count);
    count++;
    char *way = (char *)malloc(1000);
    memset(way, 0, 1000);
    strncpy(way, string, size);
    return way;
}

void util_find_ways(int n, char *way, int index) {

    if (n == 1) {
        way[index]='1';
        printf("%s\n", way);
        return;
    } else if (n == 2) {
        way[index]='2';
        printf("%s\n", way);
        char *new_way = create_new(way, index);
        new_way[index] = '1';
        util_find_ways(n-1, new_way, index+1);
    } else if (n == 3) {
        way[index]='3';
        printf("%s\n", way);
        char *new_way = create_new(way, index);
        new_way[index] = '1';
        util_find_ways(n-1, new_way, index+1);
        new_way = create_new(way, index);
        new_way[index] = '2';
        util_find_ways(n-2, new_way, index+1);
    } else {
        char *new_way = create_new(way, index);
        new_way[index] = '1';
        util_find_ways(n-1, new_way, index+1);
        new_way = create_new(way, index);
        new_way[index] = '2';
        util_find_ways(n-2, new_way, index+1);
        new_way = create_new(way, index);
        new_way[index] = '3';
        util_find_ways(n-3, new_way, index+1);
    }
}

void get_max_ways_of_reaching_n(int n) {

    char *way;
    way = (char *)malloc(1000);
    memset(way, 0, 1000);
    util_find_ways(n, way, 0);
} 
main() {
    int n;
    scanf("%d", &n);
    get_max_ways_of_reaching_n(n);
}
