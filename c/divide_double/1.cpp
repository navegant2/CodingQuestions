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
#include<unordered_map>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;
/*
 string result;
        if (numerator == 0) {
            return "0";
        }
        if (numerator < 0 && denominator < 0) {
            // Do nothing
        } else if (numerator < 0 || denominator < 0) {
            result += '-';
        }
        numerator = numerator*(numerator < 0? -1:1);
        denominator = denominator*(denominator < 0? -1:1);
        long quotient = (long)numerator/(long)denominator;
        result += to_string(quotient);
        long remainder = numerator % denominator;
        if (!remainder) {
            return result;
        }
        result += ".";
        remainder *= 10;
        unordered_map<long, long> mp;
        while (remainder) {
            long quotient = remainder/denominator;
            if (mp.find(remainder) != mp.end()) {
                result.insert(mp[remainder],"(", 1);
                result += ")";
                break;
            }
            mp[remainder] = result.size();
            result += to_string(quotient);
            remainder = (remainder%denominator)*10;
        }
        return result;
        
*/

string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += std::to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }

main() {

    int n, d;
    cin >> n;
    cin >> d;

    cout <<  fractionToDecimal(n, d) << endl;

}
