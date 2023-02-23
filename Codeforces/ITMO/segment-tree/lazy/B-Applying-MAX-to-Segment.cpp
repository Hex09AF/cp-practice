/*
    @lesson: https://codeforces.com/edu/course/2/lesson/5/1
    @problem: https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B
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
#include<unordered_map>
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
typedef long long item;

int MOD = 1e9+7;
int n, q;
int A[200200];


item NEUTRAL_ELEMENT = 0;

vector<item> SEG;
vector<item> P;

item single(int v) {
    return v;
}

item merge(item a, item b) {
    return max(a, b);
}

void build(int l, int r, int idx) {
    if (r - l == 1) {
        SEG[idx] = A[l];
        return;
    } 
    int m = (r + l) >> 1;
    build(l, m, idx << 1);
    build(m, r, idx << 1 | 1);
    SEG[idx] = merge(SEG[idx << 1], SEG[idx << 1 | 1]);
}

void update(int l, int r, int v, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return;
    if (lx >= l && rx <= r) {
        P[x] = merge(P[x], v);
        return;
    }
    int m = (rx + lx) >> 1;
    update(l, r, v, 2*x, lx,m);
    update(l, r, v, 2*x+1, m,rx);
}

item find(int i, int x, int lx, int rx) {
    if (rx - lx == 1) return P[x];
    int m = (rx + lx) >> 1;
    item rs;
    if (i < m) {
        rs = find(i,2*x,lx,m);
    } else {
        rs = find(i,2*x+1,m,rx);
    }
    return merge(rs, P[x]);
}

void input() {
    SEG.clear();
    P.clear();
    R(n, q);
}
void solve() {
    SEG.resize((n+1)*4, 0);
    P.resize((n+1)*4, 0);
    build(0, n, 1);
    FOR(i,0,q) {
        int op;
        R(op);
        if (op == 1) {
            int left, right, value;
            R(left, right, value);
            update(left, right, value, 1, 0, n);
        } else {
            int idx; R(idx);
            item pos = find(idx, 1, 0, n);
            W(pos);
        }
    }
}

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    // CASET {
        input();
        solve();
    // }
    return 0;
}