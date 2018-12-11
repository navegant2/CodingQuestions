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
#include<unordered_set>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

class LightIllumination {

public:
    LightIllumination(int size) {
        this->size = size;
    }
    void placeLight(int row, int column) {
        vertical.insert(column);
        horizontal.insert(row);
        diagonalLeft.insert(row+column);
        diagonalRight.insert(abs(row-column+size));
    }
    bool isLightUp(int row, int column) {
        if (vertical.find(column) == vertical.cend() &&
            horizontal.find(row) == horizontal.cend() &&
            diagonalLeft.find(row+column) == diagonalLeft.cend() && 
            diagonalRight.find(row-column+size) == diagonalRight.cend()) {
            return false;
        }
        return true;
    }
            

private:
    int size;
    unordered_set<int> vertical;
    unordered_set<int> horizontal;
    unordered_set<int> diagonalLeft;
    unordered_set<int> diagonalRight;

};

main() {

    int size = 8;
    LightIllumination grid(size);

    cout << "Light up at (3, 6)" << endl;    
    cout << "Light up at (2, 4)" << endl;    
    grid.placeLight(3,6);
    grid.placeLight(2,4);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // cout << "(" << i << "," << j << "): " << grid.isLightUp(i,j) << endl;
            cout << grid.isLightUp(i, j) << " ";
        }
        cout << endl;
    }

}
