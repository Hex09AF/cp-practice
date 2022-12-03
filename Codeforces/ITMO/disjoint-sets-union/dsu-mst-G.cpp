/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/2
    @problem: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/G
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
typedef long long	ll;
typedef	long double ld;
typedef	vector<vector<int>> vvi;
typedef	vector<int> vi;
typedef	pair<int,int> pii;
typedef	pair<int,pair<int,int>> pipii;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define all(a) a.begin(), a.end()

vector<int> P, R;
vector<pipii> A;

// path-compression P[u] = get(P[u]), instead only get(P[u])
int get(int u) {
    return P[u] < 0 ? u: P[u] = get(P[u]);
}

bool uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return false;
    if (R[u] == R[v]) ++R[u];
    if (R[u] < R[v]) swap(u, v);
    P[v] = u;
    return true;
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, -1);
    R.resize(n+1, 0);
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        A.push_back({c, {a, b}});
    }
    sort(all(A));
    int idx=0;
    int w=0;
    while (idx < m) {
        auto ed = A[idx].second;
        if (uni(ed.first, ed.second)) {
            w =max(w, A[idx].first);
        }
        ++idx;
    }
    cout << w;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
