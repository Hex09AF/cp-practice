/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
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

string s, t;
int n;
vector<int> A;

bool good(int x) {
    unordered_map<int,int> UM;
    for (int i=0; i<x; ++i) {
        UM[A[i]] = 1;
    }
    int j = 0;
    for (int i=0; i<n; ++i) {
        if (UM[i]) continue;
        if (j < s.size() && s[j] == t[i]) ++j;
    }
    return j == s.size();
}

void Excalibur(){
    cin >> t >> s;
    n = t.size();
    A.resize(n); for (auto&v: A) {
        cin >> v;
        --v;
    }
    int l = 0, r=n+1;
    while (l < r - 1) {
        int m = (r+l) >> 1;
        if (good(m)) l = m;
        else r = m;
    }
    cout << l;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
