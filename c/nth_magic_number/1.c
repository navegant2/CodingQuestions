#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main() {

    int n;
    scanf("%d",&n);
    int count = 1;
    int result = 0;

    while(n) {
        int temp = n & 1;
        if (temp == 1) {
            result += pow(5, count); 
        }
        count++;
        n = n >> 1;
    }
    printf("%d\n", result);
    
}
