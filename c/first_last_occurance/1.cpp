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

int get_last_occurance(vector<int> input, int val) {

    int start = 0;
    int end = input.size()-1;

    while (start <= end) {

        int mid = start + (end-start)/2;

        //cout << "s:" << start << " e:" << end << " m:" << mid << " val@mid:" << input[mid] << endl;

        if (start == end && input[mid] != val) {
            return -1;
        }
       
        if (input[mid] == val && (mid == input.size()-1 || input[mid+1] > val)) {
            return mid;
        } else if (val < input[mid] ) {
            end = mid-1;
        } else if (val > input[mid]) { // val > input[mid]
            start = mid+1;
        } else {
            start = mid;
        }
    }
    return -1;
}
            

int get_first_occurance(vector<int> input, int val) {
   
    int start = 0;
    int end = input.size()-1;

    while (start <= end) {

        int mid = start + (end-start)/2;

        if (start == end && input[mid] != val) {
            return -1;
        }
        
        if (input[mid] == val && (mid == 0 || input[mid-1] < val)) {
            return mid;
        } else if (val > input[mid]) {
            start = mid+1;
        } else {    // val <= input[mid]
            end = mid; 
        }
    }
    return -1;
}

main() {

    vector<int> input1 = { 1, 2, 2, 2, 4, 7, 9};
    vector<int> input2 = { 1, 2 };

    for (int i = 0; i < input1.size(); i++) {
        cout << i << ":" << input1[i] << "  ";
    }
    cout << endl;
    int val = 2;
    cout << "2  findex:" << get_first_occurance(input1, val) << endl;
    cout << "2  lindex:" << get_last_occurance(input1, val) << endl;
    val = 9;
    cout << "9  findex:" << get_first_occurance(input1, val) << endl;
    cout << "9  lindex:" << get_last_occurance(input1, val) << endl;
    val = 10; 
    cout << "10  findex:" << get_first_occurance(input1, val) << endl;
    cout << "10  lindex:" << get_last_occurance(input1, val) << endl;
    val = 0; 
    cout << "0  findex:" << get_first_occurance(input1, val) << endl;
    cout << "0  lindex:" << get_last_occurance(input1, val) << endl;

}
