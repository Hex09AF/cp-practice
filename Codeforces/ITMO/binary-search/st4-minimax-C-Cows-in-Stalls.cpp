/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/3
    @problem: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
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

int n, k;
vector<int> A;

bool good(int m) {
    int cnt = 1, lst = A[0];
    for (int i=0; i<n; ++i) {
        if (A[i] - lst >= m) {
            ++cnt; lst = A[i];
        }
    }
    return cnt >= k;
}

void Excalibur(){
    cin >> n >> k; A.resize(n);
    for (auto &a: A) cin >> a;
    int l=0, r=A[n-1] - A[0] + 1;
    while (l<r-1) {
        int m = (l+r)>>1;
        if (good(m)) l = m;
        else r = m;
    }
    cout << l;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
