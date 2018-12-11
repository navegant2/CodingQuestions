#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int reverse(int x) {
        int isNegative = 0;
        
        if (x < 0) {
            isNegative = 1;
            x = -1 * x;
        }
        int r_x = 0;
        while (x) {
            int temp = x % 10;
            if (r_x * 10 + temp < r_x) {
                r_x = 0;
                break;
            }
            r_x = 10 * r_x + temp;
        printf(" Temp: %d \n", r_x);
            x = x/10;
        }
        if (isNegative) {
            r_x = -1 * r_x;
        }
        return r_x;
}

main() {

    int x = 1534236469;
    int y = reverse(x);

    printf("%d\n", y);

}
