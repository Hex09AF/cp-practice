/*
    @problem: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A
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

int n, m;
VL a, b, segA, segB;

LL neutral = 0;

LL merge(LL a, LL b) {
    return a + b;
}

void build(int l, int r, int idx, VL& seg, VL& ar) {
    if (r-l==1) { seg[idx] = ar[l]; return; }
    int m = (l+r)>>1;
    build(l, m, idx<<1, seg, ar); build(m, r, idx<<1|1, seg, ar);
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

void update(int l, int r, int idx, int pos, int v, VL& seg) {
    if (r-l==1) { seg[idx] = v; return; }
    int m = (r+l)>>1;
    if (pos < m) { update(l, m, idx<<1, pos, v, seg);
    } else { update(m, r, idx<<1|1, pos, v, seg); }
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

LL get(int l, int r, int ql, int qr, int idx, VL& seg) {
    if (ql >= r || qr <= l) return neutral;
    if (ql <= l && qr >= r) return seg[idx];
    int m = (l+r)>>1;
    return merge(get(l, m, ql, qr, idx<<1, seg), get(m, r, ql, qr, idx<<1|1, seg));
}

void solve() {
    if (!SZ(a)) a.PB(1);
    segA.resize(SZ(a) * 4);
    segB.resize(SZ(b) * 4);
    build(0, SZ(a), 1, segA, a);
    build(0, SZ(b), 1, segB, b);
    R(m);
    while (m--) {
        int q, u, v;
        R(q, u, v);
        if (q) {
            LL sumA = get(0, SZ(a), u / 2 - !(u&1), v / 2, 1, segA);
            LL sumB = get(0, SZ(b), u / 2, v / 2 + (v&1), 1, segB);
            if (u&1) {
                W(sumB - sumA);
            } else {
                W(sumA - sumB);
            }
        } else {
            if (u&1) {
                update(0, SZ(b), 1, u / 2, v, segB);
            } else {
                update(0, SZ(a), 1, u/2 - !(u&1), v, segA);
            }
        }
    }
}

void input() {
    R(n);
    FOR(i,0,n) {
        int x; R(x);
        if (i&1) a.PB(x);
        else b.PB(x);
    }
}

int main(){ cin.tie(0); ios_base::sync_with_stdio(false);
    // CASET {
        input();
        solve();
    // }
    return 0;
}