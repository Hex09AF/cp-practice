/*
    @problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
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


void Excalibur(){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int &v: A) cin >> v;
    for (int i=0; i<k; ++i) {
        int x; cin >> x;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (x > A[m]) {
                l = m + 1;
            } else if (x < A[m]){
                r = m - 1;
            } else {
                l = m;
                break;
            }
        }
        if (l <= r) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
