/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
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

ll m, n;

struct item {
    ll t, z, y;
};

vector<item> A;

bool good(ll x) {
    ll res = 0;
    for (int i=0; i<n; ++i) {
        ll ball = x / (A[i].t * A[i].z + A[i].y) * A[i].z;
        ball += min(A[i].z, x % (A[i].t * A[i].z + A[i].y) / A[i].t);
        res += ball;
    }
    return res >= m;
}

void Excalibur(){
    cin >> m >> n;
    A.resize(n);
    for (int i=0; i<n; ++i) {
        ll t, z, y; 
        cin >> t >> z >> y;
        A[i] = {t, z, y};
    }
    ll l=-1, r=1e17;
    while (l < r-1) {
        ll mid = (l + r) >> 1;
        if (good(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    for (int i=0; i<n; ++i) {
        ll ball = r / (A[i].t * A[i].z + A[i].y) * A[i].z;
        ball += min(A[i].z, r % (A[i].t * A[i].z + A[i].y) / A[i].t);
        cout << min(m, ball) << " ";
        m -= min(m, ball);
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
