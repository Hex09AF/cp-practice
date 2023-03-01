/*
    @lesson: https://codeforces.com/edu/course/2/lesson/5/2
    @problem: https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
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
const int MOD = 1e9+7;

const item DEFAULT_ITEM = 0LL;
const item OUT_ITEM = LLONG_MAX;

struct segtree {
    int size;
    vector<item> operations;
    vector<item> mins;

    int lNode(int x) {
        return x * 2 + 1;
    }
    int rNode(int x) {
        return x * 2 + 2;
    }
    int mid(int l, int r) {
        return (l + r) / 2;
    }
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        operations.assign(2 * size, DEFAULT_ITEM);
        mins.assign(2 * size, DEFAULT_ITEM);
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        /**
         *           lx          rx
         *           -  -  -  -  -
         *  -  -  -                 -  -  -
         *  l     r                 l     r
        */
        if (lx >= r || l >= rx) return;
        if (lx >= l && rx <= r) {
            operations[x] += v;
            mins[x] += v;
            return;
        }
        int m = mid(lx, rx);
        add(l, r, v, lNode(x), lx, m);
        add(l, r, v, rNode(x), m, rx);
        mins[x] = std::min(mins[lNode(x)], mins[rNode(x )]) + operations[x];
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    item min(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return OUT_ITEM;
        if (lx >= l && rx <= r) {
            return mins[x];
        }
        int m = mid(lx, rx);
        item m1 = min(l, r, lNode(x), lx, m);
        item m2 = min(l, r, rNode(x), m, rx);
        return std::min(m1, m2) + operations[x];
    }

    item min(int l, int r) {
        return min(l, r, 0, 0, size);
    }
};

int n, m;
void input() {
    R(n, m);
}
void solve() {
    segtree st;
    st.init(n);
    FOR(i,0,m) {
        int op;
        R(op);
        if (op == 1) {
            int left, right, value;
            R(left, right, value);
            st.add(left, right, value);
        } else {
            int l, r;
            R(l, r);
            W(st.min(l, r));
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