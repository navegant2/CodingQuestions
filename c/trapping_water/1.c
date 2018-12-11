#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


int get_trapped_water(int n, int *array) {
   // initialize output
    int result = 0;
     
    // maximum element on left and right
    int left_max = 0, right_max = 0;
     
    // indices to traverse the array
    int lo = 0, hi = n-1;
     
    while(lo <= hi) 
    {
        if(array[lo] < array[hi])
        {
            if(array[lo] > left_max)
            // update max in left
            left_max = array[lo];
            else
            // water on curr element = max - curr
            result += left_max - array[lo];
            lo++;
        }
        else
        {
            if(array[hi] > right_max)
            // update right maximum
            right_max = array[hi];
            else
            result += right_max - array[hi];
            hi--;
        }
    }
     
    return result;
}

main() {
    int n;
    scanf("%d", &n);
    int i;
    int *array = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int result = get_trapped_water(n, array);
    printf("%d\n", result);
}
