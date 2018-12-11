#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

/*

ab* = a*b
ab+ = a+b
ab*c+ = a * b + c
ab+c* = (a+b)*c
ab+cd+*ef+* = (a+b) * (c+d) * (e+f)

*/

bool is_operator(char ch) {

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return true;
    }
    return false;
}

string make_expression(string operand1, string operand2, char operator1) {

    string result;
    switch(operator1) {

        case '+':
                result = operand1 + '+' + operand2; 
                break; 
        case '-':
                result = operand1 + '-' + operand2; 
                break; 
        case '*':
                result = operand1 + '*' + operand2; 
                break; 
        case '/':
                result = operand1 + '/' + operand2; 
                break; 
    }
    return result;
}

    
string postfix_to_infix(string postfix) {

    queue<string> myQueue;

    for (int i = 0; i < postfix.size(); i++) {
        if (is_operator(postfix[i])) {
            string operand1 = myQueue.front();
            myQueue.pop();
            string operand2 = myQueue.front();
            myQueue.pop();
            myQueue.push(make_expression(operand1, operand2, postfix[i]));
        } else {
            myQueue.push((char)string(postfix[i]));
        }
    }
    return myQueue.front();
} 
    

main() {

    string postfix;

    cin >> postfix;

    cout << postfix_to_infix(postfix) << endl;

}
