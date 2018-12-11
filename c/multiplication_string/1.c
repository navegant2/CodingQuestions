#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int to_number(char c) {
    return c - '0';
}
int to_alphabet(int num) {
    return num + '0';
}
void fix_remainders (int *array, int index) {
    int i;
    for (i = 0; i < index; i++) {
        int remainder = array[i] % 10;
        int quotient = array[i] / 10;
        array[i] = remainder;
        array[i+1] = array[i+1] + quotient;
    }
}
void _multiplication_string(char *string1, char *string2, int *array, int size) {
	int i, j, z;
    int index = 0;
	for (j = strlen(string2)-1; j >=0; j--) {
        z = index;
	    for (i = strlen(string1)-1; i >=0; i--) {
			int value = to_number(string1[i])*to_number(string2[j]);
			array[z] = array[z] + value;
            z++;
        }
        index++; 
    }
    fix_remainders(array, z);
}
void swap(char *s1, char *s2) {
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void reverse_string(int *array, char *string, int size) {
    int i;
    int index = 0;

    for (i = size-1; i >= 0; i--) {
        string[index++] = to_alphabet(array[i]); 
    }
}

char *multiplication_string(char *string1, char *string2) {

	int size1 = strlen(string1);
	int size2 = strlen(string2);

	int size3 = size1 > size2? size1:size2;
	char *string3 = (char *)malloc(sizeof(char)*(size3*2));
    memset(string3, 0, size3*2);
	int *array = (int *)malloc(sizeof(int)*(size3*2));
    memset(array, 0, sizeof(int)*size3*2);
	
	if (size1 > size2) {	
		_multiplication_string(string1, string2, array, size3*2);
	} else {
		_multiplication_string(string2, string1, array, size3*2);
	}
    reverse_string(array, string3, size3*2);
	return string3;
}

	


main() {
	char string1[100];
	char string2[100];
    char *string3;

	scanf("%s", string1);
	scanf("%s", string2);

	string3 = multiplication_string(string1, string2);
	printf("%s\n", string3);

}
	
