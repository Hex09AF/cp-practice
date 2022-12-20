/*
    @problem: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
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

void Excalibur(){
    int n; ll p;
    cin >> n >> p;
    vector<int> a(n);
    ll tot = 0;
    for (auto &x: a) { 
        cin >> x; 
        tot += x;
    }
    for (int i=0; i<n-1; ++i) a.push_back(a[i]);
    ll s = 0, l = 0;
    ll rs = LLONG_MAX, posRs = 0;
    ll k = p/tot*n;
    p %= tot;
    for (int i=0; i<2*n-1; ++i) {
        s += a[i];
        while (l <= i && s - a[l] >= p) {s -= a[l]; ++l;}
        if (s >= p && i-l+1 < rs) {
            rs = i-l+1;
            posRs = l;
        }
    }
    cout << posRs % n + 1 << " " << k + rs << "\n";
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
