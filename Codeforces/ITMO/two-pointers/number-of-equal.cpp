/*
    @lesson: https://codeforces.com/edu/course/2/lesson/9/1
    @problem: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
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
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void Excalibur(){
    int n, m; cin >> n >> m;
    vector<int> A(n);
    for (int&v: A) cin >> v;
    ll ret = 0;
    int l=0, r=0;
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        while (l < n && A[l] < x) ++l;
        while (r < n && A[r] <= x) ++r;
        ret += r - l;
    }
    cout << ret;
}

void ExcaliburMap(){
    map<int, int> A;
    int n, m; cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (A.find(x) == A.end()) {
            A[x] = 1;
        } else {
            A[x] += 1;
        }
    }
    ll ret = 0;
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        if (A.find(x) != A.end()) {
            ret += A[x];
        }
    }
    cout << ret;
}

int main(){ios::sync_with_stdio(false); 
Excalibur();return 0;}