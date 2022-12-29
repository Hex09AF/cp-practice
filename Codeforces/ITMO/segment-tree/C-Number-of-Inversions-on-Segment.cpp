/**
 * @problem: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
 * @helper: https://codeforces.com/edu/course/2/lesson/4/4?#comment-946147
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
struct item {
    int cnt[41] = {0};
    LL rs = 0;
};
item neutral;
vector<int> a;
vector<item> seg;

item merge(item a, item b) {
    item c;
    c.rs += a.rs + b.rs;
    FOR(i, 0, 41) {
        c.cnt[i] = a.cnt[i] + b.cnt[i];
        FOR(j, 0, i) {
            c.rs += 1LL * a.cnt[i] * b.cnt[j];
        }
    }
    return c;
}

void build(int l, int r, int idx) {
    if (r-l==1) seg[idx].cnt[a[l]] = 1;
    else {
        int m = (l+r)>>1;
        build(l,m,idx<<1);
        build(m,r,idx<<1|1);
        seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
    }
}

void update(int l, int r, int idx, int pos, int v) {
    if (r-l == 1) {
        seg[idx].cnt[a[l]] = 0;
        seg[idx].cnt[v] = 1;
        a[l] = v;
    } else {
        int m = (l+r)>>1;
        if (pos < m) update(l, m, idx<<1, pos, v);
        else update(m, r, idx<<1|1, pos, v);
        seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
    }
}

item get(int l, int r, int ql, int qr, int idx) {
    if (qr <= l || ql >= r) return neutral;
    if (ql <= l && qr >= r) return seg[idx];
    int m = (l+r)>>1;
    return merge(get(l,m,ql,qr,idx<<1), get(m,r,ql,qr,idx<<1|1));
}

void solve() {
    build(0, n, 1);
    while(q--) {
        int type, u, v;
        R(type, u, v);
        if (type == 1) {
            item rs = get(0, n, u-1, v, 1);
            W(rs.rs);
        } else {
            update(0, n, 1, u - 1, v);
        }
    }
}

void input() {
    R(n,q);
    a.resize(n);
    for (auto &x: a) R(x);
    seg.resize(n << 2);
}

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    // CASET {
        input();
        solve();
    // }
    return 0;
}