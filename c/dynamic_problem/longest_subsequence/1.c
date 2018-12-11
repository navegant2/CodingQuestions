#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int max2 (int X, int Y) {
    if (X > Y) {
        return X;
    } else {
        return Y;
    }
}

int max3(int A,int B, int C) {
   
    return max2(A, max2(B,C));
}  
    

int lss(char *str1, char *str2, int m, int n) {


    if (m == 0 || n == 0) {
        return 0;
    }

    if (str1[m-1] == str2[n-1]) {
        return 1 + lss(str1, str2, m-1, n-1);
    } else {
        return max2(lss(str1, str2, m, n-1), lss(str1, str2, m-1,n));
    }
}
main() {

    char str1[100];
    char str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    int result = lss(str1, str2, strlen(str1), strlen(str2));
    printf("%d\n", result);

}
