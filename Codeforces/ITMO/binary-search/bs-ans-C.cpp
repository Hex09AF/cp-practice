/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
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

ll n, a, b;

bool good(ll m) {
    if (a > b) swap(a,b);
    if (m < a) return false;
    m -= a;
    return 1 + m / a + m / b >= n;
}

void Excalibur(){
    cin >> n >> a >> b;
    ll l=0, r=1e17;

    while (l < r-1) {
        ll m = (r + l) >> 1;
        if (good(m)) r = m;
        else l = m;
    } 

    cout << r;
}

int main(){ios::sync_with_stdio(false);
int t = 1; while (t--) Excalibur(); return 0;}