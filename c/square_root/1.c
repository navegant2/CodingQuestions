#include<stdio.h>
int get_squareroot(int n) {

    int start = 1;
    int end = n;
    int answer = 0;
    int mid ; 
    int mid2 ; 

    while(start <= end) {
    
        mid = (start + end) /2;
        mid2 = mid * mid;
        if (mid2 == n) {
            answer = mid;
            break;
        } else if ( mid2 < n) {
            start = mid + 1;
            answer = mid;
        } else {
            end = mid - 1;
        }
    }
    return answer; 

}
main() {

    int n;
    scanf("%d", &n);
    int result = get_squareroot(n);
    printf("%d\n", result);
    
}
