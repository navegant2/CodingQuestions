#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<list>
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


char to_char(int val) {
    return '0'+val;
}
string to_string(int N) {

    string s;
    while(N) {
        int temp = N % 10;
        s = to_char(temp) + s;
        N = N/10;
    }
    return s;
}
int get_value(char ch) {
    return ch - '0';
}
int to_integer(string s) {

    int value = 0;
    for (int i = 0; i < s.size(); i++) {
        value = value * 10 + get_value(s[i]); 
    }
    return value;
}
int get_next_palindrome(int N) {

    bool isNegative = false;
    if (N < 0) {
        isNegative = true;
        N = -1* N;
    }
    string s = to_string(N);
    int i = 0;
    int len = s.size();
    int j = 0;
    int mid =  len/2;


cout << "S:" << s << " len:" << len << endl;

    /* When all digits are '9', like 99, 999 return 101, 1001 etc */
    for (i = 0; i < len; i++) {
        if (s[i] != '9') {
            break;
        }
    }
    if (i == len) {
        return N+2;
    }

    i = mid-1;
    /* Len = 4, mid = 2, i = (1, 0) j = (2, 3) */
    /* Len = 5, mid = 2, i = (1, 0) j = (3, 4) */
    if (len % 2 == 0) {
        j = mid;
    } else {
        j = mid+1;
    }
    bool isLeftLess = false;
    while(i >= 0 && j < len && s[i] == s[j]) {
        i--; j++;
    }

    if (i < 0 || s[i] < s[j] ) isLeftLess = true;

cout << "S:" << s << " len:" << len << " isLeftLess:" << isLeftLess << endl;
    while(i >= 0) {
        s[j++] = s[i--];
    }
    
    if (isLeftLess) {

        // Add one to the centre like 12921 => 13031; 123377 => 123321=> 124421
        i = mid-1;
        int carry = 1;

        if (len % 2 == 0) {
            j = mid;
        } else {
            j = mid+1;
            if (s[mid] <= '8') 
            {    
                s[mid]++; carry = 0; 
            }
            else {
                s[mid] = '0';
            }
        }
         
        while(i >= 0 && carry) {

            if (s[i] <= '8') {
                s[i]++;
                s[j]++;
                break;
            } else {
                s[i] = s[j] = '0';
            }
            i--; j++;
        }

    }
    return isNegative? - 1* to_integer(s) : to_integer(s); 
}
main() {

    int N;
    cin >> N;

    int P = get_next_palindrome(N);
    cout << P << endl;

/*
    string s = to_string(N);
    cout << "s:" << s << endl;
    cout << "i:" << to_integer(s) << endl;
*/



}
