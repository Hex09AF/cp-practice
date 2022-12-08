/*
    @lesson: https://codeforces.com/edu/course/2/lesson/9/2
    @problem: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
    @time-complexity: O(log(n))  (!!not in amortization!!)
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
typedef unsigned long long	ll;
typedef	long double ld;
typedef	vector<int> vi;
typedef	vector<vi> vvi;
typedef	pair<int,int> pii;
typedef	pair<int,pii> pipii;
typedef	pair<pii,pii> piipii;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define all(a) a.begin(), a.end()

vector<ll> SEG;
vector<ll> A;

ll build(int l, int r, int idx) {
    if (r - l == 1) {
        SEG[idx] = A[l];
    } else {
        int m = (r + l) >> 1;
        SEG[idx] = __gcd(build(l, m, idx << 1), build(m, r, idx << 1 | 1));
    }
    return SEG[idx];
}

void update(int l, int r, int i, int v, int idx) {
    if (r - l == 1) {
        SEG[idx] = v;
        return;
    }
    int m = (r + l) >> 1;
    if (i < m) {
        update(l, m, i, v, idx << 1);
    } else {
        update(m, r, i, v, idx << 1 | 1);
    }
    SEG[idx] = __gcd(SEG[idx << 1], SEG[idx << 1 | 1]);
}

ll query(int l, int r, int ql, int qr, int idx) {
    if (l >= qr || r <= ql) return 0;
    if (l >= ql && r <= qr) return SEG[idx];
    int m = (r + l) >> 1;
    return __gcd(query(l, m, ql, qr, idx << 1), query(m, r, ql, qr, idx << 1 | 1));
}

void Excalibur(){
    int n; cin >> n;
    A.resize(n);
    SEG.resize(n * 4);
    for (auto &a: A) cin>>a;
    build(0, n, 1);
    int rs = INT_MAX;
    int l = 0;
    for(int i=0; i<n; ++i){
        while (l <= i && query(0, n, l, i+1, 1) == 1) {
            rs = min(rs, i-l+1);
            ++l;
        }
    }
    cout << (rs == INT_MAX ? -1 : rs);
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
