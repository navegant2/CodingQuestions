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

int minimum_messiness(vector<string> words, int max_width) {

    vector<int> messiness_value(words.size(), numeric_limits<int>::max());   
    int i, j;

    int remaining_blanks = max_width - words[0].size();
    messiness_value[0] = remaining_blanks * remaining_blanks;
    
    for (i = 1; i < words.size(); i++) {

        cout << i << ":------------------------------------------------------------" << endl;
        remaining_blanks = max_width - words[i].size();
        messiness_value[i] = messiness_value[i-1] + remaining_blanks * remaining_blanks;
        cout << "remainng_blanks:" << remaining_blanks << "  messiness_value[" << i << "]:" << messiness_value[i] << endl;

        for (j = i-1; j >= 0; j--) {
            cout << j << ":$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;
            remaining_blanks -= (words[j].size() + 1);
            if (remaining_blanks < 0) {
                break;
            } 
            int first_j_messiness = j-1<0 ? 0:messiness_value[j-1];
            cout << "first_j_messiness:" << messiness_value[j-1] << "  j-1:" << j-1 << endl;
            int current_messiness = remaining_blanks * remaining_blanks;
            cout << "current_messiness:" << current_messiness << endl;  
            cout << "Before: messiness_value[" << i << "]:" << messiness_value[i] << endl;  
            messiness_value[i] = min(messiness_value[i], first_j_messiness + current_messiness); 
            cout << "After: messiness_value[" << i << "]:" << messiness_value[i] << endl;  
        }
        for (int k = 0; k <= i; k++) {
            cout << k << " : " << messiness_value[k] << endl;
        }
    }
    return messiness_value.back();
}


main() {

    int N;
    cin >> N;
    vector<string> words(N);

    int i;
    for (i = 0; i < N; i++) {
        cin >> words[i];
    }
    int result =  minimum_messiness(words, 11);
    cout << result << endl;
}
