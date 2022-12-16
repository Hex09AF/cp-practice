/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/3
    @problem: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B
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

int n, k;
vector<int> A;

bool good(ll m) {
    ll su = 0;
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        su += A[i];
        if (su > m) {
            su = A[i];
            ++cnt;
        }
    }
    return cnt + 1 <= k;
}

void Excalibur(){
    cin >> n >> k; A.resize(n);
    ll l=0, r=1e15;
    for (auto &x: A) {
        cin >> x;
        l = max(l, 1LL* x);
    }
    --l;
    while (l<r-1) {
        ll m = (l+r)>>1;
        if (good(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
