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
#include<cmath>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

int is_palindrom(int n) {

    int div = pow(10, (int)log10(n));

    cout << "log:" << log10(n) << endl;
    cout << "n:" << n << " div:" << div << endl;

    while(n) {
        if (n % 10 != n/div) {
            return 0;
        }
        n = n % (div);
        n = n/10;
        div = div/100;
    }
    return 1;
}


main() {

    int N;
    cin >> N;

    cout << is_palindrom(N) << endl;
}
