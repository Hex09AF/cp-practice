/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/2
    @problem: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
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

vector<int> P, R, MN;

// path-compression P[u] = get(P[u]), instead only get(P[u])
int get(int u) {
    return P[u] == u ? u: P[u] = get(P[u]);
}

void uni(int u, int v) {
    P[u] = P[v];
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+2);
    for (int i=1; i<=n+1; ++i) {
        P[i] = i;
    }
    while (m--) {
        char q; int u; cin >> q;
        if (q == '-') {
            cin >> u;
            uni(u, u+1);
        } else {
            cin >> u;
            u = get(u);
            if (u == n+1) u = -1;
            cout << u << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
