/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/3
    @problem: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
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
vector<int> N;
int get(int u) {
    return P[u] < 0 ? u : P[u] = get(P[u]);
}

bool uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    P[x] = y;
    return true;
}

void Excalibur(){
    int n, q; cin >> n >> q;
    P.resize(n, -1);
    N.resize(n, 0);
    for (int i=0; i<n-1; ++i) {
        N[i] = i+1;
    }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        --x; --y;
        if (x > y) swap(x, y);
        if (t == 1) {
            uni(x, y);
        } else if (t == 2) {
            while (x < y) {
                uni(x, x+1);
                int cur = x;
                x = N[x];
                N[cur] = max(N[cur], y);
            }
        } else {
            if (get(x) == get(y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}


/**
 * 1 2 3 4 - - 7 8 9 10 - - 13 14 - 16
*/