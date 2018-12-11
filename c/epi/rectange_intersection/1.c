#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _rectangle {
    int x;
    int y;
    int width, height;
} Rectangle;


int max (int a, int b) {
    return a > b ? a:b;
}
int min (int a, int b) {
    return a < b ? a : b;
}

int IsIntersection(Rectangle *r1, Rectangle *r2) {

    return r2->x <= r1->x + r1->width && r1->x <= r2->x + r2->width &&
            r2->y <= r1->y + r1->height && r1->y <= r2->y + r2->height;

} 

Rectangle *RectangeIntersection(Rectangle *r1, Rectangle *r2) {

    Rectangle *result;
    if (IsIntersection(r1, r2)) {
        result = (Rectangle *)malloc(sizeof(Rectangle));
        result->x = max(r1->x, r2->x);
        result->y = max(r1->y, r2->y);
        result->width = min(r1->x+r1->width, r2->x+r2->width) - max (r1->x, r2->x);
        result->height = min(r1->y+r1->height, r2->y+r2->height) - max(r1->y, r2->y);
        return result; 
    }
    return NULL;
}

main() {

    Rectangle r1;
    Rectangle r2;

    scanf("%d %d %d %d", &r1.x, &r1.y, &r1.width, &r1.height);
    scanf("%d %d %d %d", &r2.x, &r2.y, &r2.width, &r2.height);

    Rectangle *result = RectangeIntersection(&r1, &r2);

    if (result != NULL) {
        printf("%d %d %d %d \n", result->x, result->y, result->width, result->height);
    }
}
