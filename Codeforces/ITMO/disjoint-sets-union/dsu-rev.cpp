/*
    @lesson: https://codeforces.com/edu/course/2/lesson/9/1
    @problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
    @time-complexity: O(n)
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
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

vector<int> P;

int get(int u) {return P[u] < 0 ? u : P[u] = get(P[u]);}
void uni(int u, int v) {u = get(u); v = get(v); if (u == v) return; P[v] = u;}

void Excalibur(){
    int n, m, k; cin >> n >> m >> k;
    P.resize(n+1, -1);
    vector<string> res;
    vector<pii> edg;
    vector<pair<string, pii>> q;
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
    }
    for (int i=0; i<k; ++i) {
        string s;
        int u, v; cin >> s >> u >> v;
        q.push_back({s, {u, v}});
    }
    for (int i=k-1; i>=0; --i) {
        int u = get(q[i].second.first);
        int v = get(q[i].second.second);
        if (q[i].first[0] == 'a') {
            if (get(u) == get(v)) res.push_back("YES");
            else res.push_back("NO");
        } else {
            uni(u, v);
        }
    }

    for (int i=res.size()-1; i>=0; --i){
        cout << res[i] << "\n";
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
