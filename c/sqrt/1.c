#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int square_root(int N) {
   
    int start = 1;
    int end = N;
    int mid;
    int mid2;
    int answer;

    while(start <= end) {
        mid = (start+end)/2;
        mid2 = mid * mid;
        if (mid2 == N) {
            return mid;
        } else if (mid2 < N) {
            start = mid+1;
            answer = mid;
        } else {
            end = mid-1;
        }
    }
    return answer;

} 

main() {

    int N;
    scanf("%d", &N);

    int result = square_root(N);
    printf("%d\n", result);


}
