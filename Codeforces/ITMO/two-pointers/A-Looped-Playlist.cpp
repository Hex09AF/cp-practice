/*
    @problem: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
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

void Excalibur(){
    int n; ll p;
    cin >> n >> p;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    for (int i=0; i<n-1; ++i) a.push_back(a[i]);
    ll s = 0, l = 0, rs = LLONG_MAX, posRs = 0;
    for (int i=0; i<2*n-1; ++i) {
        s += a[i];
        while (s - a[l] >= p) {
            s -= a[l]; ++l;
        }
        if (s >= p) {
            if (rs > (i-l+1)) {
                rs = i-l+1;
                posRs = l;
            }
        } else {
            if (i-l+1 == n) {
                ll tmpRs = (p/s)*n;
                ll need = p%s;
                for (int j=l; need && j<l+n; ++j) {
                    need -= a[j];
                    ++tmpRs;
                    if (need <= 0) {
                        break;
                    }
                }
                if (rs > tmpRs) {
                    rs = tmpRs;
                    posRs = l;
                }
                s -= a[l];
                ++l;
            }
        }
    }
    cout << posRs + 1 << " " << rs << "\n";
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
