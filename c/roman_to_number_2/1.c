#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char romans[9] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', 0 };
int values[9] = {  1,   5 , 10 , 50,  100, 500, 1000, 0};

int get_values(char c) {

    int i = 0;    
    while(romans[i] != 0 ) {
        if (romans[i] == c) {
            return values[i];
        }
        i++;
    }
    return 0;
}

int convert_to_number(char *string) {
    int len = strlen(string);
    int number = 0;

    int i;
    for (i = 0; i < len; i++) {
        int num1  = get_values(string[i]);
        int num2 = 0;
        if (i+1 < len) {
            num2 = get_values(string[i+1]);
        } 
        if (num2 > num1) {
            number += num2 - num1;
            i++;
        } else {
            number += num1;
        }
    }
    return number;
}
     

main() {

    char string[1000];

   
    scanf("%s", string);
    
    int number = convert_to_number(string); 
    printf("%d\n", number);


}
