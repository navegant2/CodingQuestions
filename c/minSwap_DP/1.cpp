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

 int minSwap(vector<int>& A, vector<int>& B) {
        const size_t n = A.size();
        vector<int> swap(n, n), no_swap(n, n);
        swap[0] = 1;
        no_swap[0] = 0;

        cout << "0" << " A[0]:" << A[0] << " B[0]:" << B[0] << " swap[0]:" << swap[0] << " no_swap[0]:" << no_swap[0] << endl; 
        for (size_t i = 1; i < n; ++i) {

            
            cout << "Before ==> i:" << i << " A[i]:" << A[i] << " B[i]:" << B[i] << " swap[i]:" << swap[i] << " no_swap[i]:" << no_swap[i] << endl; 
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                // If we swap position i, we need to swap position i - 1.
                swap[i] = swap[i - 1] + 1;
                
                // If we don't swap position i , we should not swap position i - 1.
                no_swap[i] = no_swap[i - 1];
            }
            cout << "Middle ==> i:" << i << " A[i]:" << A[i] << " B[i]:" << B[i] << " swap[i]:" << swap[i] << " no_swap[i]:" << no_swap[i] << endl; 
            
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                // If we swap position i, we should not swap position i - 1.
                swap[i] = std::min(swap[i], no_swap[i - 1] + 1);
                
                // If we don't swap position i, we should swap position i - 1.
                no_swap[i] = std::min(no_swap[i], swap[i - 1]);
            }
            cout << "After ==> i:" << i << " A[i]:" << A[i] << " B[i]:" << B[i] << " swap[i]:" << swap[i] << " no_swap[i]:" << no_swap[i] << endl << endl; 
        }
        
        return std::min(swap.back(), no_swap.back());
    }

main() {

    int N;
    cin >> N;
    vector<int> A, B;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    cout << minSwap(A, B) << endl;

}
