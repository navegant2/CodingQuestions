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
#include<climits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

main() {

    int t = 1;
    while(t--)
    {
        int n, i;
        cin>>n;
        int a[n], s[n], max_sum=INT_MIN, temp;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int k;
        cin>>k;
        temp = a[0];
        s[0] = a[0];
        for(i=1; i<n; i++)
        {
            temp = max(a[i],temp+a[i]);
            s[i] = temp;
            cout << sum << " ";
        }
        cout << endl;
        int sum=0;
        for(i=0; i<k; i++)
        {
            sum += a[i];
        }
        temp = sum;
        for(i=k; i<n; i++)
        {
            sum = sum + a[i] - a[i-k];
            temp = max(temp, sum);
            temp = max(temp, sum+s[i-k]);
        }
        cout<<temp<<endl;
    }
    return 0;
}
