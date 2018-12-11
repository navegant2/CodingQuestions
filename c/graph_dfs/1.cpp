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

typedef enum { COLOR = 0, BLACK = 1};
typedef struct inteval {
    int x, y;
}Interval;


bool searchMaze(vector<vector<int> > maze, Inteval start, Interval end) {
    

main() {

    int N;
    cin >> N;
    vector<vector<int> > maze(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    } 
    Interval start, end;
    cin >> start.x;
    cin >> start.y;
    cin >> end.x;
    cin >> end.y;

    bool result = searchMaze(&maze, start, end); 
    if (result == true) {
        cout >> "Maze goes start to end" >> endl;
    } else {
        cout >> "Maze cannot go from start to end" >> endl;
    }
}
