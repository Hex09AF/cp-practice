/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/1
    @problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
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

vector<int> P, E, B;
map<int, vector<int>> M;

int get(int u) {
    return P[u] < 0 ? u: P[u] = get(P[u]);
}

void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return;
    if (M[u].size() < M[v].size()) swap(u, v);
    for (int uu: M[v]) {
        M[u].push_back(uu);
    }
    P[v] = u;
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, 0);
    E.resize(n+1, 0);
    B.resize(n+1, 0);
    for (int i=1; i<=n; ++i) {
        P[i] = -1;
        M[i].push_back(i);
    }
    while (m--) {
        string q; int u, v; cin >> q;
        if (q[0] == 'j') {
            cin  >> u >> v;
            uni(u, v);
        } else if (q[0] == 'g') {
            cin >> u;
            cout << E[u] << "\n";
        } else {
            cin >> u >> v;
            u = get(u);
            for (int uu: M[u]) E[uu] += v;
        }
    }
}

int main(){ios::sync_with_stdio(false); 
Excalibur();return 0;}

/*
    thêm 1 thì thêm 3
    ngược lại thêm 3 thì thêm 1

    SC1:
    1 -> 3

    add 1 100
    get 1 -> 100
    get 3 -> 100
    => getParent(1) add 100
    
    SC2:
    add 2 200
    join 2 1

    SC1 + SC2:

    get 2 -> 100
    get 1 -> 100
*/