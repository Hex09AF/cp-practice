/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/3
    @problem: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
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

struct item {
    ld pos, spd;
};
int n;
vector<item> A;

bool good(ld m) {
    ld mnl = LLONG_MIN;
    ld mxl = LLONG_MAX;
    for (int i=0; i<n; ++i) {
        mnl = max(mnl, A[i].pos - m * A[i].spd);
        mxl = min(mxl, A[i].pos + m * A[i].spd);
    }
    return mnl <= mxl;
}

void Excalibur(){
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) {
        ld x, y; cin >> x >> y;
        A[i] = {x, y};
    }
    ld l=0, r=INT_MAX;
    for (int i=0; i<100; ++i) {
        ld m = (r+l)/2;
        if (good(m)) {
            r = m;
        } else { 
            l = m;
        }
    }
    cout << setprecision(20) << r;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
