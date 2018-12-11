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


  void shortestPathAllKeysHelper(vector<string>& grid, vector<vector<int>> visited, 
                                   int max_keys, vector<int> keys_collected, int steps,
                                    int *min_steps, int row, int col) {
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        visited[row][col] = 1;
        
        for (int i = 0; i < dirs.size(); i++) {
            int next_row = row + dirs[i][0];
            int next_col = col + dirs[i][1];
            
            if (next_row >= 0 && next_row < grid.size() && 
                next_col >= 0 && next_col < grid[0].size() && 
                grid[next_row][next_col] != '#'  && !visited[next_row][next_col]) {
        
                // cout << "next_row:next_col->" << next_row << ":" << next_col << endl;
                if (grid[next_row][next_col] == '.') {
                    shortestPathAllKeysHelper(grid, visited, max_keys,keys_collected, steps+1, min_steps, next_row, next_col);
                } else if (grid[next_row][next_col] >= 'a' && grid[next_row][next_col] <= 'f') {
                    char key = grid[next_row][next_col];
                    keys_collected[key-'a']++;
                    shortestPathAllKeysHelper(grid, visited, max_keys,keys_collected, steps+1, min_steps, next_row, next_col);
                } else if (grid[next_row][next_col] >= 'A' && grid[next_row][next_col] <= 'F') {
                    char lock = grid[next_row][next_col];
                    if (keys_collected[lock-'A']) {
                        shortestPathAllKeysHelper(grid, visited, max_keys,keys_collected, steps+1, min_steps, next_row, next_col);
                    }
                }
            }
            int key;
            for (key = 0; key < max_keys; key++) {
                if (keys_collected[key] == 0) {
                    break;
                }
            }
            if (key == max_keys) {
                if (*min_steps == -1) {
                    *min_steps = 1 + steps;
                } else {
                    *min_steps = min(*min_steps, 1 + steps);
                }
            }
        }
        
    }
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int min_steps = -1;
        int max_keys = 0;
        int start_row = 0; int start_col = 0;
        
        if (grid.size() == 0) {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '@') {
                    start_row = i;
                    start_col = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    max_keys++;
                }
            }
        }
        vector<int> keys_collected(max_keys, 0);
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        shortestPathAllKeysHelper(grid, visited, max_keys, keys_collected, 0, &min_steps, start_row, start_col);
        return min_steps;
    }
main() {


}
