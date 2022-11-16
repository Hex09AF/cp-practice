/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/1
    @problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
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

vector<int> P, R;

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
    if (R[u] == R[v]) ++R[u];
    // join the smaller set to the larger one.
    if (R[u] > R[v]) {
        P[v] = u;
    } else {
        P[u] = v;
    }
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, -1); R.resize(n+1, 1);
    while (m--) {
        string q; int u, v; cin >> q >> u >> v;
        if (q[0] == 'u') {
            uni(u, v);
        } else {
            if (get(u) == get(v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main(){ios::sync_with_stdio(false); 
Excalibur();return 0;}