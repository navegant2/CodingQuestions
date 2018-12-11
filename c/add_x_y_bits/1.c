#include<stdio.h>
 
int Add(int x, int y)
{
    // Iterate till there is no carry  
    while (y != 0)
    {
        printf("BB: x: %d, y : %d \n", x, y);
        // carry now contains common 
        //set bits of x and y
        int carry = x & y;  
 
        // Sum of bits of x and y where at 
        //least one of the bits is not set
        x = x ^ y; 
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
        printf("AA: x: %d, y : %d, carry:%d \n", x, y, carry);
    }
    return x;
}
 
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d + %d = %d", x, y, Add(x, y));
    return 0;
}
