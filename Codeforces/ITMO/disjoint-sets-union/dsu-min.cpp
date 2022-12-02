/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/1
    @problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

vector<int> P, R, MN, MX;

// path-compression P[u] = get(P[u]), instead only get(P[u])
int get(int u) {
    return P[u] < 0 ? u: P[u] = get(P[u]);
}

// rank heuristic
void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return;
    // calucalate how large the set is
    // join the smaller set to the larger one.
    if (R[u] > R[v]) {
        P[v] = u;
        R[u] += R[v];
    } else {
        P[u] = v;
        R[v] += R[u];
    }
    MN[u] = min(MN[u], MN[v]);
    MX[u] = min(MX[u], MX[v]);
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, -1); R.resize(n+1, 1);
    MN.resize(n+1, INT_MAX);
    MX.resize(n+1, 0);
    for (int i=0; i<=n; ++i) {
        MN[i] = i;
        MX[i] = i;
    }
    while (m--) {
        string q; int u, v; cin >> q;
        if (q[0] == 'u') {
            cin >> u >> v;
            uni(u, v);
        } else {
            cin >> u;
            u = get(u);
            cout << MN[u] << " " << MX[u] << " " << R[u] << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
