#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int get_max_value(char *str, int len) {
   // Store first character as integer
    // in result
    int res = str[0] -'0';
    int i;
 
    // Start traversing the string
    for (i = 1; i < len; i++)
    {
        // Check if any of the two numbers
        // is 0 or 1, If yes then add current
        // element
        if (str[i] == '0' || str[i] == '1' ||
            str[i-1] == '0' || str[i-1] == '1' )
            res += (str[i]-'0');
 
        // Else multiply
        else
            res *= (str[i]-'0');
    }
 
    // Return maximum value
    return res;
}

/*
int get_max_value(int len, int *array) {
    int max_value = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (max_value == 0 || max_value == 1 || array[i] == 0 || array[i] == 1) {
            max_value = max_value + array[i];
        } else {
            max_value = max_value * array[i];
        }
    }
    return max_value;
}
*/

void convert_string_to_array(int len, char *string, int *array) {
    int i;
    for (i = 0; i < len; i++) {
        array[i] = string[i]-'0';
    }
}
main() {
    char string[100];
    scanf("%s", string);
    int len = strlen(string);

    int *array = (int *)malloc(sizeof(int)*len);
    convert_string_to_array(len, string, array);

    int max_value = get_max_value(string, len);
    printf("%d\n", max_value);

}
    
