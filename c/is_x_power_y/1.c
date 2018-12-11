#include<stdio.h>

int is_x_power_y(int n) {
    int i;
    
    for (i = 2; i < n/2; i++) {
        int temp = n;
        while( temp > 0) {
            temp = temp/i;
            if (temp == i) {
                return 1;
            }
        }
    }
    return 0;
}

main() {
    int n = 0;
    scanf("%d", &n);

    printf("Result:%s\n",is_x_power_y(n)?"true":"false");
} 

