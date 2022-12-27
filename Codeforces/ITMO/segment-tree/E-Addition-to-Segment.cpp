/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/3
    @problem: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E
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
typedef	vector<int> vi;
typedef	vector<vi> vvi;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

#define FOR(a, b, c) for (int a = b; a < c; ++a)
#define FU(i, n) FOR(i, 0, n)
#define all(a) a.begin(), a.end()

vector<ll> seg;

int neutral = 0;

ll merge(ll a, ll b) {
    return a + b;
}

void build(int l, int r, int idx) {
    if (r-l==1) {
        seg[idx] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(l, m, idx<<1);
    build(m, r, idx<<1|1);
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

void update(int l, int r, int idx, int pos, int v) {
    if (r-l==1) {
        seg[idx] += v;
        return;
    }
    int m = (r+l)>>1;
    if (pos < m) {
        update(l, m, idx<<1, pos, v);
    } else {
        update(m, r, idx<<1|1, pos, v);
    }
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

ll get(int l, int r, int ql, int qr, int idx) {
    if (ql >= r || qr <= l) return neutral;
    if (ql <= l && qr >= r) return seg[idx];
    int m = (l+r)>>1;
    return merge(get(l, m, ql, qr, idx<<1), get(m, r, ql, qr, idx<<1|1));
}

void Excalibur(){
    int n, m; cin >> n >> m;
    seg.resize(4*(n+1));
    build(0, n+1, 1);
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(0, n+1, 1, l, v);
            update(0, n+1, 1, r, -v);
        } else {
            int pos; cin >> pos;
            cout << get(0, n+1, 0, pos+1, 1) << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
