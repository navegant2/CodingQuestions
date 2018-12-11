#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int dp[300][300];

int get_minimum(int a, int b) {

    if (a < b) { 
        return a;
    } else { 
        return b;
    }
}

int find_minimum_squares(int x, int y) {
    
    int i;
    int j;
    int x_minimum = INT_MAX;
    int h_minimum = INT_MAX;

    if (x == y) {
        return 1;
    }
    if (dp[x][y]) {
        return dp[x][y];
    }
    for (i = 1; i <= x/2; i++) {
        x_minimum = get_minimum(find_minimum_squares(x - i, y) + find_minimum_squares(i,y), x_minimum);
    }
    for (j = 1; j <= y/2; j++) {
        h_minimum = get_minimum(find_minimum_squares(x , j) + find_minimum_squares(x,y-j), h_minimum);
    }
    dp[x][y] = get_minimum(x_minimum, h_minimum); 
}

main() {

    int x;
    int height;
    int min_squares = 0;

    scanf("%d",&x);
    scanf("%d",&height);

    memset(dp, 0, sizeof(dp));

    min_squares = find_minimum_squares(x, height);
    printf("%d\n", min_squares);
}

    

