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


void swap_string(string &s, int start, int end) {

    int i = start; int j = end;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}
void reverse_words(string &s) { 

    int size = s.size();
    swap_string(s, 0, size-1); 
    int start = 0;
cout << "t:" << s << endl;

    for (int i = 0; i <= size; i++) {
        if (i == size || s[i] == ' ') {
            swap_string(s, start, i-1);
            start = i+1;
        } 
    }        

}

main() {

    string s = "this is our blue sky a";
    reverse_words(s); 

    cout << s << endl;
}
        
