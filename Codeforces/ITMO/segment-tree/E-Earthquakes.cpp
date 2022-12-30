/**
 * @problem: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E
 * @helper: https://codeforces.com/edu/course/2/lesson/4/4?#comment-786237
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<iomanip>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
int n, q;
typedef int item;
item neutral = INT_MAX;
vector<item> seg;

item merge(item a, item b) {
    return min(a, b);
}

void build(int l, int r, int idx) {
    if (r-l==1) {
        seg[idx] = INT_MAX;
    } else {
        int m = (l+r)>>1;
        build(l,m,idx<<1);
        build(m,r,idx<<1|1);
        seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
    }
}

void update(int l, int r, int idx, int pos, int v) {
    if (r-l == 1) {
        seg[idx] = v;
    } else {
        int m = (l+r)>>1;
        if (pos < m) update(l, m, idx<<1, pos, v);
        else update(m, r, idx<<1|1, pos, v);
        seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
    }
}

int get(int l, int r, int ql, int qr, int idx, int p) {
    if (l >= qr || r <= ql) return 0;
    if (l >= ql && r <= qr) {
        if (seg[idx] > p) {
            return 0;
        }
    }
    if (r-l == 1) {
        if (seg[idx] <= p) {
            seg[idx] = INT_MAX;
            return 1;
        }
        return 0;
    }
    int m = (r + l) >> 1;
    int rs = get(l, m, ql, qr, idx << 1, p) + get(m, r, ql, qr, idx << 1 | 1, p);
    seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
    return rs;
}

void solve() {
    build(0, n, 1);
    while(q--) {
        int type, u, v;
        R(type, u, v);
        if (type == 2) {
            int p; R(p);
            item rs = get(0, n, u, v, 1, p);
            W(rs);
        } else {
            update(0, n, 1, u, v);
        }
    }
}

void input() {
    R(n,q);
    seg.resize(n << 2);
}

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    // CASET {
        input();
        solve();
    // }
    return 0;
}
