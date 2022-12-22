/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/3
    @problem: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
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

vector<int> P;
vector<int> L;

pair<int,int> get(int u) {
    if (P[u] < 0) return {u, 0};
    auto val = get(P[u]);
    P[u] = val.first;
    L[u] = (L[u] + val.second);
    return {P[u], L[u]};
}

void uni(int u, int v) {
    auto U = get(u);
    auto V = get(v);
    if (U.first == V.first) return;
    P[U.first] = V.first;
    L[U.first] = (U.second + V.second + 1);
    return;
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, -1); L.resize(n+1, 1);
    while (m--) {
        int u, v;
        int q; cin >> q;
        if (q == 1) {
            cin >> u >> v;
            uni(u, v);
        } else {
            cin >> u;
            cout << get(u).second << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
