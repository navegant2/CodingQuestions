#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stack>


int to_number(char c) {
    return c - '0';
}
int is_number(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}
int is_alphabet(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ) {
        return 1;
    }
    return 0;
}
int is_left_bracket(char c) {
    if (c == '[') {
        return 1;
    }
    return 0;
}
void evaluate_string(std::stack<int>& numbers, std::stack<char>& alphabets) {
    int number = numbers.top();
    int i;
    numbers.pop();

    std::string s = "";
    std::string new_s = "";
    while (alphabets.top() != '[') {
        s = alphabets.top() + s;
        alphabets.pop();
    }
    alphabets.pop();// pop '['
    while (number > 0) {
        new_s.append(s);
        number--;
    }
    for (i = 0; i < new_s.size(); i++) {
        alphabets.push(new_s[i]);
    }
}
void make_string(std::stack<char>& alphabets, std::string& s) {
    
    while(!alphabets.empty()) { 
        s = alphabets.top() + s;
        alphabets.pop();
    }
    return;
}
void expand_the_string(char *string) {
    int i;
    int len = strlen(string);
    std::stack<int> numbers;
    std::stack<char> alphabets;
    std::string output_string = "";

    for (i = 0; i < len; i++) {
        if (is_number(string[i])) {
            numbers.push(to_number(string[i]));
        } else if (is_alphabet(string[i])) {
            alphabets.push(string[i]);
        } else if (is_left_bracket(string[i])) {
            alphabets.push(string[i]);         
        } else { // if ']' 
            evaluate_string(numbers,alphabets);
        }
    }
    while(!numbers.empty()) {
        evaluate_string(numbers, alphabets);
    }
    make_string(alphabets, output_string);

    printf("%s\n", output_string.c_str());
}

main() {
    char string[100];
    scanf("%s", string);

    expand_the_string(string);
}
    
