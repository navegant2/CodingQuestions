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


double pow(double x, int n) {
        if (n==0) return 1;
        if (n%2) {
            return x*pow(x*x,n/2);
        } else {
            return pow(x*x,n/2);
        }
}
main() {

    double x;
    int n;
    cin >> x;
    cin >> n;
    if (n < 0) {
        n = -n;
        x = 1/x;
    }
    cout << pow(x, n) << endl;
}
