#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _interval {
    int x;
    int  y;
} Interval;

int in_between(Interval *intervals, int i, int j) {
    if (intervals[i].x == -1) {
        return 0;
    }
    if (intervals[i].x >= intervals[j].x && intervals[i].x <= intervals[j].y) {
        return 1;
    } 
    if (intervals[j].x >= intervals[i].x && intervals[j].x <= intervals[i].y) {
        return 1;
    } 
    return 0;
} 
void find_overlapping_intervals(int n, Interval *intervals) {
    int i = 0;
    int j = 0;
    
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (in_between(intervals, i, j)) {
                intervals[j].x = intervals[i].x<intervals[j].x?intervals[i].x:intervals[j].x; 
                intervals[j].y = intervals[i].y>intervals[j].y?intervals[i].y:intervals[j].y;
                intervals[i].x = -1;
                intervals[i].y = -1;
            }
        }
    }
}

main() {
    int n;
    Interval *intervals;
    int i;

    scanf("%d", &n);
    intervals = (Interval *)malloc(sizeof(Interval)*n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].x, &intervals[i].y);
    }
    for (i = 0; i < n; i++) {
        printf("(%d %d)", intervals[i].x, intervals[i].y);
    }
    printf("\n");
    find_overlapping_intervals(n, intervals);
    for (i = 0; i < n; i++) {
        if (intervals[i].x != -1) {
            printf("(%d %d)", intervals[i].x, intervals[i].y);
        }
    }
    printf("\n");
}

