#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num_at (char c) {
    return c - '0';
}
int to_char(int num) {
    return num + '0';
}
void swap(char *string, int i, int j) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
}

void _sum_of_number_strings(char *num1, char *num2, int num1_len, int num2_len, char *result) {
    int i = 0, j = 0;
    int k = 0;
    int carry = 0;
    memset(result, 0, num1_len);

    for (i = num1_len-1, j = num2_len-1; i >=0 && j >= 0; i--, j--) {
        int temp = num_at(num1[i]) + num_at(num2[j]) + carry;
        result[k++] = to_char(temp % 10);
        carry = temp/10;
    }
    for ( ; i >= 0; i--) {
        int temp = num_at(num1[i]) + carry;
        result[k++] = to_char(temp % 10);
        carry = temp/10;
    }
    if (carry > 0) {
        result[k++] = to_char(carry);
    }
    
    for (i = 0; i < k/2; i++) {
        swap(result, i, k - i - 1);
    }
}

void sum_of_number_strings(char *num1, char *num2, char **result) 
{
    int i = 0, j = 0;
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);

    if (num1_len >= num2_len) {
        *result = (char *)malloc(sizeof(char)*(num1_len +1));
        _sum_of_number_strings(num1, num2, num1_len, num2_len, *result);
    } else {
        *result = (char *)malloc(sizeof(char)*(num2_len +1));
        _sum_of_number_strings(num2, num1, num2_len, num1_len, *result);
    }
    return;
} 

void main() {
    char num1[100];
    char num2[100];
    char *num3;

    scanf("%s", num1);
    scanf("%s", num2);

    sum_of_number_strings(num1, num2, &num3);
    printf("result: %s\n", num3);

}
