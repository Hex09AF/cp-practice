/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
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

string s;
ll nb, ns, nc;
ll kb, ks, kc;
ll pb, ps, pc;
ll r;

bool good(ll x) {
    return r - max(pb*(x*nb - kb), 0LL) - max(ps*(x*ns - ks),0LL) - max(pc*(x*nc - kc),0LL)  >= 0;
}

void Excalibur(){
    cin >> s;
    for (auto x: s) {
        if (x == 'B') ++nb;
        if (x == 'C') ++nc;
        if (x == 'S') ++ns;
    }
    cin >> kb >> ks >> kc;
    cin >> pb >> ps >> pc;
    cin >> r;
    ll l=0, r=1e15;
    while (l<r-1) {
        ll m = (r+l)>>1;
        if (good(m)) l=m;
        else r=m;
    }
    cout << l;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
