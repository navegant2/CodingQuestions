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


void allocate_memory(void *a, vector<int> sizes, int index) {

    if (index == sizes.size()) {
        return;
    }
    (*a) = malloc(sizeof(int) * size[index]);
    for (int i = 0; i < size[index]; i++) {
        allocate_memory(&((*a)[i]), sizes, index+1);
    }
}

main() {

    int ******a;
    vector<int> sizes{ 10, 9, 8, 7, 6, 5 };

    allocate_memory(&a, sizes, 0);

    print_a(a);

}
