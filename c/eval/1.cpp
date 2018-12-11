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


    bool is_number(string s) {
       
        int start = 0;
        if (s[0] == '-') {
            start = 1;
        } 
        for (int i = start; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }
    int get_number(string s) {
        return atoi(s.c_str());
    }
    int evaluate(int num1, int num2, string operation) {

        int result = 0;
        if (operation == "+") {
            result = num1 + num2;
        } else if (operation == "-") {
            result = num1 - num2;
        } else if (operation == "*") {
            result = num1 * num2;
        } else if (operation == "/") {
            cout << num1 << " : " << num2 << " : " << operation << endl;
            result = num1/num2;
        }   
        cout << "operation:" << operation << " Num1:" << num1 << " Num2: " << num2 << " Result is " << result << endl; 
        return result;
    
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            cout << "current token is " << s << endl;
            if (is_number(s)) {
                numbers.push(get_number(s));
            } else {
                int num1, num2;
                if (!numbers.empty()) {
                    num2 = numbers.top();
                    numbers.pop();
                }
                if (!numbers.empty()) {
                    num1 = numbers.top();
                    numbers.pop();
                } 
                int result = evaluate(num1, num2, s);
                numbers.push(result);
            }
        }
        return numbers.top();
    }

main() {

    const char *arr[] = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    vector<string> tokens(arr, arr  + sizeof(arr)/sizeof(arr[0]));

    int result = evalRPN(tokens);
    cout << result << endl;

}
