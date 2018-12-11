#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
};

int max(int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    } else if (y >= z && y >= x) {
        return y;
    } else  {
        return z;
    }
}
int maxPoints(struct Point* points, int pointsSize) {
    int i,j;
    int max_points_in_line = 1;
    int temp_points = 0;
    int x_points = 0;
    int y_points = 0;
    int d_points = 0;
    
    if (pointsSize == 0) {
        return 0;
    }
    for (i = 0; i < pointsSize-1; i++) {
            x_points = 1;
            y_points = 1;
            d_points = 1;
        for (j = i+1; j < pointsSize; j++) {
            if (points[i].x == points[j].x) {
                x_points++;
            } 
            if( points[i].y == points[j].y) {
                y_points++;
            }
            if( points[i].x - points[j].x == points[i].y - points[j].y) {
                d_points++;
            }
            printf("i:%d, j:%d, points[i].x:%d, points[j].x:%d, points[i].y:%d, points[i].y:%d\n",
                        i, j, points[i].x, points[j].x, points[i].y, points[j].y);
        }
        temp_points = max(x_points, y_points, d_points);
        if (max_points_in_line < temp_points) {
            max_points_in_line = temp_points;
        }
    }
    return max_points_in_line;
}

main() {

    int n;
    int i;
    scanf("%d", &n);

    struct Point *points = (struct Point *)malloc(sizeof(struct Point)*n);

    for (i = 0; i < n; i++) {
        scanf("%d:%d", &points[i].x, &points[i].y);
    }
    int result = maxPoints(points, n);
    printf("Result is: %d\n", result);
}

