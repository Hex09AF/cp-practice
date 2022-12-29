/**
 * @problem: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
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
int r, n, m;
struct item {
    int a[2][2];
};
item neutral;
vector<item> a, seg;

item mul(item &a, item &b) {
    item c;
    FOR(i,0,2) {
        FOR(j,0,2) {
            c.a[i][j] = 0;
            FOR(k,0,2) {
                // c.a[i][j] += a.a[i][k] * b.a[k][j];
                c.a[i][j] += (a.a[i][k] % r) * (b.a[k][j] % r) % r;
                c.a[i][j] %= r;
            }
        }
    }
    return c;
}

item merge(item a, item b) {
    return mul(a, b);
}

void build(int l, int r, int idx) {
    if (r-l==1) seg[idx] = a[l];
    else {
        int m = (l+r)>>1;
        build(l,m,idx<<1);
        build(m,r,idx<<1|1);
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
    while(m--) {
        int left, right;
        R(left, right);
        item rs = get(0, n, left-1, right, 1);
        FOR (i,0,2) FOR(j,0,2) cout << rs.a[i][j] << " \n"[j==1];
    }
}

void input() {
    R(r,n,m);
    a.resize(n);
    seg.resize(n << 2);
    FOR(i,0,2) FOR(j,0,2) neutral.a[i][j] = (i==j);
    FOR(k,0,n) {
        FOR(i,0,2) FOR(j,0,2) R(a[k].a[i][j]);
    }
}

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    // CASET {
        input();
        solve();
    // }
    return 0;
}