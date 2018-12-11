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

 int kth(int a[], int m, int b[], int n, int k) {

        if (m < n) {
            cout << "m:" << m << " n:" << n << " k:" << k << endl;
            return kth(b,n,a,m,k);
        }
        cout << "m:" << m << " n:" << n << " k:" << k << endl;
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << " || ";
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl; 

        int j = min(n,k/2);
        int i = k-j;
        cout << "m:" << m << " n:" << n << " k:" << k << " i:" << i << " j:" << j << endl;
        cout << "a[i-1]:" << a[i-1] << " b[j-1]:" << b[j-1] << endl;
        
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m+n)/2;
        cout << "From Main:k : " << k+1 << endl;
        int m1 = kth(a,m,b,n,k+1);
        cout << "m1:" << m1 << endl;
        if ((m+n)%2==0) {
            cout << "From Main:k : " << k << endl;
            int m2 = kth(a,m,b,n,k);
            cout << "m2:" << m2 << endl;
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }

main() {
   
    int a[] = {1, 3, 5, 7, 9, 11};
    int b[] = {2, 4, 6, 8};

    cout << findMedianSortedArrays(a, 6, b, 4) << endl;

}
