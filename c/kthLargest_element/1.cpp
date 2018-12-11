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


void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

bool myLess(int a, int b) {
     return a < b;
}
int partition(vector<int> array, int lo, int hi) {

    int i = lo;
    int j = hi;

    while(true) {
    
        while(i < hi && myLess(array[++i],array[lo]));
        while(j > lo && myLess(array[lo], array[--j]));

        if (i < j) {
            swap(array[i], array[j]);
        } else {
            break;
        }
    }
    swap(array[lo], array[j]);
    return j;
}

int getKthLargestElement(vector<int> array, int k) {

    int lo = 0;
    int hi = array.size()-1;
    k = array.size()-k;

    while(lo < hi) {

        int j = partition(array, lo, hi);
        if (j < k) {
            lo = j + 1;
        } else if (j > k) {
            hi = j-1;
        } else {
            return array[k];
        }
    }
}


main() {

    int N;
    cin >> N;
    vector<int> array;

    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        array.push_back(temp);
    }

    int k;
    cin >>  k;

    cout << "KthLargestElement:" << getKthLargestElement(array, k) << endl;


}
