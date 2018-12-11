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


vector<string> singles = { "", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine" };
vector<string> doubles = { "ten", " eleven", " twelve", " thirteen", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " nineteen" };
vector<string> tens = { "", "" , " twenty", " thirty", " fourty", " fifty", " sixty", " seventy", " eighty", " ninety", " hundred"};
vector<string> others = { "" , " thousand", " million", " billion", " trillion" }; 


// This is expected to be less than 1000 always
string get_words(int n) {

    if (n == 0) {
        return "";
    }
    string s;

    if (n/100) {
        s = singles[n/100] + " hundred ";
    }
    n = n%100;
    if (n/10 == 0) {
        n = n%10;
        s += singles[n%10];
    }else if (n/10 > 1) {
        s += tens[n/10];
        n = n%10;
        s += singles[n%10];
    } else {
        s += doubles[n%10];
    } 
    return s;
}

string num_to_words(int n) {

    if (n == 0) {
        return "zero";
    }

    int count3 = 0;
    string result;

    while (n) {
        int temp = n%1000;
        n = n/1000;
        count3++;
        
        string s = get_words(temp);
        if (n) {
            result = others[count3] + s + result;
        } else {
            result = s + result  ;
        }
    }
    return result.substr(1);
}

main() {
    int N;
    cin >> N;
    string s = num_to_words(N);
    cout << s << endl;
}
