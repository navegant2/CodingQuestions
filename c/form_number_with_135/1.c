#include<stdio.h>
#include<string.h>

int form_n_from_135(int n) {

    if (n <= 0) {
        printf("\n");
        return;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2 || n == 3) {
        return 2;
    }
    if (n == 4) {
        return 3;
    }
    if (n == 5) {
        return 4;
    }
    return form_n_from_135(n-1) + form_n_from_135(n-3) + form_n_from_135(n-5);
}

main() {
    int n;
    scanf("%d", &n);
    printf("ouptut is %d\n", form_n_from_135(n));

}
