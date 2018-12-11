#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>


int to_number (char c) {
    return c - '0';
}
int is_number(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}
int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || c == '(' ) {
        return 1;
    }
    return 0;
}
void do_arithmetic_operation(std::stack<int>& operands, int value1, int value2, int operation) {

    if (operation == '*') { 
        operands.push(value1*value2);
    } else if (operation == '/' ) {
        operands.push(value1/value2);
    } else if (operation == '+') {
        operands.push(value1+value2);
    } else if (operation == '-' ) {
        operands.push(value1 - value2);
    }
    printf("operation value: %d\n", operands.top());
}

int isPrecedenceHigher(char c, char top_c) {
    if (c == '*' || c == '/') {
        return 1;
    } else {
        return 0;
    }
}
void get_complete_number(std::stack<int>& operands, char *string, int *index) {
    int i = *index;
    int value = 0;
    int base = 1;
    while(is_number(string[i])) {
        value = base*value+to_number(string[i]);
        base = base * 10;
        i++;    
    }
    *index = i;
    printf("number: %d\n", value);
    operands.push(value);
}
        

void take_operator_action(std::stack<int>& operands, std::stack<char>& operators, char *string, int *index) {

    char c = string[*index];

printf("operator: %c\n", c);    
    switch(c) {

        case '/':
        case '*':
        case '+':
        case '-':
                if ( (operators.empty() && (c == '*' || c == '/')) || 
                    (!(operators.empty()) && isPrecedenceHigher(c, operators.top()))) {
                    int value1 = operands.top();
                    operands.pop();
                    *index = *index+1;
                    get_complete_number(operands, string, index);
                    int value2 = operands.top(); 
                    operands.pop();
                    do_arithmetic_operation(operands, value1, value2, c);
                } else {
                    operators.push(c);
                    *index = *index + 1;
                }
                break;
        
        case '(':
                operands.push(c); 
                *index = *index + 1;
                break;
        
        case ')':
                char operation = operators.top();
                operators.pop();
                while(operation != '(') {
                    int value1 = operands.top();
                    operands.pop();
                    int value2 = operands.top();
                    operands.pop();
                    do_arithmetic_operation(operands, value1, value2, operation);
                    operation = operators.top();
                    operators.pop();
                }
                *index = *index + 1;
                break;
    }
    return;
}

int perform_arithmetic(char *string) {
    std::stack<int> operands;   
    std::stack<char> operators;   

    int length = strlen(string);
    int i  = 0;
    while(i < length) {
        char c = string[i];
        if (is_operator(c)) {
            take_operator_action(operands, operators, string, &i);
        } else if (is_number(c)) {
            get_complete_number(operands, string, &i);
        } else {
            printf("wrong input\n");
            exit(1);
        }
    }
    while (!operators.empty()) {
printf("Finally: operators: %lu, operands:%lu\n", operators.size(), operands.size());

        int  value1 = operands.top();
        operands.pop();
        int value2 = operands.top();
        operands.pop();
        char operation = operators.top();
        operators.pop();
        do_arithmetic_operation(operands, value1, value2, operation);
    }
    return operands.top();
}
main() {

    char string[1000];
    int value;

    scanf("%s", string);
    printf("%s\n", string);
    value = perform_arithmetic(string);
    printf("%d\n", value);
}
