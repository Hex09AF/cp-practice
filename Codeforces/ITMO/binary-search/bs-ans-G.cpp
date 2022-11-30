/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
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

ll k;
ll n;
vector<ll> A;

bool good(ll x) {
    ll needs = x * k;
    for (ll i=0; i<n; ++i) {
        needs -= min(x, A[i]);
    }
    return needs <= 0;
}

void Excalibur(){
    cin >> k >> n;
    A.resize(n); for(auto&a:A)  cin>>a;
    ll l=0, r=1e15;
    while (l<r-1) {
        ll m = (r+l)>>1;
        if (good(m)) l=m;
        else r=m;
    }
    cout << l;
}

int main(){ios::sync_with_stdio(false);
int tc = 1; while (tc--) Excalibur(); return 0;}
