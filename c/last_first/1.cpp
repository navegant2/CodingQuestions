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

int GetRightPosition(int A[], int l, int r, int key) 
{ 
    int m; 
  
    while( r - l > 1 ) 
    { 
        m = l + (r - l)/2; 
  
        if( A[m] <= key ) 
            l = m; 
        else
            r = m; 
    } 
  
    return l; 
} 
  
// Input: Indices Range (l ... r] 
// Invariant: A[r] >= key and A[l] > key 
int GetLeftPosition(int A[], int l, int r, int key) 
{ 
    int m; 
  
    while( r - l > 1 ) 
    { 
        m = l + (r - l)/2; 
  
        if( A[m] >= key ) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
int left = GetLeftPosition(A, -1, size-1, key); 
int right = GetRightPosition(A, 0, size, key); 


