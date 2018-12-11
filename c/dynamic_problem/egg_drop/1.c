#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int min(int A, int B) {
    if (A < B) {
        return A;
    } else {
        return B;
    }
}

int min_iterations(int floors, int eggs) {

    if (floors == 0 || floors == 1) {
        return floors;
    }
    if (eggs == 1) {
        return floors;
    }
    return 1 + min(min_iterations(floors-1, eggs-1), min_iterations(floors-1, eggs));
}   

main() {

    int floors;
    int eggs;

    scanf("%d %d", &floors, &eggs);

    int result = min_iterations(floors, eggs);
    printf("%d\n", result);


}
