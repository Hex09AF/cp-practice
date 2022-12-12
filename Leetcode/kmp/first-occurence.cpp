/*
    @problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
    @helper: https://youtu.be/M9azY7YyMqI
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <numeric>

using namespace std;
#define DB(x) 	cerr << #x << " is " << (x) << "\n";
typedef long long	ll;
typedef	long double ld;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

class Solution {
public:
    int strStr(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        vector<int> lcp(nt);
        lcp[0] = 0;
        int l = 0;
        for (int i=1; i<nt; ++i) {
            while (l > 0 && t[i] != t[l]) {
                l = lcp[l-1];
            }
            l = l + (t[i] == t[l]);
            lcp[i] = l;
        }
        l = 0;
        for (int i=0; i<ns; ++i) {
            while (l > 0 && s[i] != t[l]) {
                l = lcp[l-1];
            }
            if (l + (s[i] == t[l]) == nt) {
                return i-l;
            }
            l = l + (s[i] == t[l]);
        }
        return -1;
    }
};

void Excalibur(){}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
