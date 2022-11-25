/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
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

bool good(ll m, ll h, ll w, ll n) {
    return (m/h) * (m/w) >= n;
}

void Excalibur(){
    ll w, h, n; cin >> w >> h >> n;
    ll l = 0, r = 1;
    while (!good(r,h,w,n)) r*=2;
    while (l < r - 1) {
        ll m = r - ((r-l) >> 1);
        if (good(m,h,w,n)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}

int main(){ios::sync_with_stdio(false);
int t = 1; while (t--) Excalibur(); return 0;}
