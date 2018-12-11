#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include <iostream>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


int toint(const string &s) //The conversion function
{
    cout << "toint :" << s << "\n";
    return atoi(s.c_str());
}

bool isValid(const string &s) {
    if (s.size() > 3) {
        return false;
    }
    if (s[0] == '0' && s.size() > 1) {
        return false;
    }
    int val = toint(s);
    if (val < 0 || val > 255) {
        return false;
    }
    return true;
}

vector<string> get_valid_ipaddress(const string &s) {

    vector<string> results;

    for (int i = 1; i < 4 && i < s.size(); i++) {
        string first = s.substr(0, i);
        cout << "first:" << first << "\n";
        if (isValid(first)) {
            for (int j = 1; j < 4 && i + j < s.size(); j++) {
                string second = s.substr(i, j);
        cout << "second:" << second << "\n";
                if (isValid(second)) {
                    for (int k = 1; k < 4 && i + j + k < s.size(); k++) {
                        string third = s.substr(i+j, k);
                        string fourth = s.substr(i+j+k);
        cout << "third:" << third << "\n";
        cout << "fourth:" << fourth << "\n";
                        if (isValid(third) && isValid(fourth)) {
                            results.push_back(first + "." + second + "." + third + "." + fourth);
                        }
                    }
                }
            }
        }
    }
    return results;
}
main() {

    string ipaddr; 

    cin >> ipaddr;

    vector<string> results = get_valid_ipaddress(ipaddr);
    int i = 0; 

    for (i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
    }
}
