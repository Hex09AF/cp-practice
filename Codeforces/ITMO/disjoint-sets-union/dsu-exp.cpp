/*
    @lesson: https://codeforces.com/edu/course/2/lesson/7/1
    @problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
    @time-complexity: O(log(n))  (!!not in amortization!!)
    @comment: https://codeforces.com/edu/course/2/lesson/7/1/practice#comment-696262
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

vector<int> P, B, R;

int get(int u) {
    return P[u] < 0 ? u: get(P[u]);
}

int getExp(int u) {
    int exp = 0;
    while (P[u] > 0) {
        exp += B[u];
        u = P[u];
    }
    return exp + B[u];
}

void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return;
    if (R[u] == R[v]) ++R[u];
    if (R[u] < R[v]) swap (u, v);
    // Critical thinking (when merge two set)
    // Khi gộp 2 set lại, bởi vì không có sự liên quan kinh nghiệm giữa 2 set
    // Ta phải trừ hoặc huỷ đi kinh nghiệm của set con bằng cách - kinh nghiệm nút cha
    B[v] -= B[u];
    P[v] = u;
}

void Excalibur(){
    int n, m; cin >> n >> m;
    P.resize(n+1, -1);
    B.resize(n+1, 0);
    R.resize(n+1, 0);

    while (m--) {
        string q; int u, v; cin >> q;
        if (q[0] == 'j') {
            cin  >> u >> v;
            uni(u, v);
        } else if (q[0] == 'g') {
            cin >> u;
            cout << getExp(u) << "\n";
        } else {
            cin >> u >> v;
            u = get(u);
            B[u] += v;
        }
    }
}

int main(){ios::sync_with_stdio(false); 
Excalibur();return 0;}
