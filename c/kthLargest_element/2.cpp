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


    void exch(int *i, int *j) {
        int *tmp = i;
        *i = *j; 
        *j = *tmp;
    }

    bool myLess(int v, int w) {
        return v < w;
    }
    int partition(vector<int> *a_ptr, int lo, int hi) {

        int i = lo;
        int j = hi + 1;
        vector<int> &a = *a_ptr;
        while(true) {
            while(i < hi && myLess(a[++i], a[lo]));
            while(j > lo && myLess(a[lo], a[--j]));
            if(i >= j) {
                break;
            }
            exch(&a[i], &a[j]);
        }
        exch(&a[lo], &a[j]);
        return j;
    }


int findKthLargest(vector<int> nums, int k) {

        k = nums.size()- k;
        int lo = 0;
        int hi = nums.size()- 1;
        while (lo < hi) {
            int j = partition(&nums, lo, hi);
            cout << "lo:" << lo << " hi:" << hi << " j:" << j << endl;
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
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

    cout << "KthLargestElement:" << findKthLargest(array, k) << endl;



}
