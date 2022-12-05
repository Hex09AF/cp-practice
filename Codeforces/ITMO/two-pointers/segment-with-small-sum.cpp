/*
    @lesson: https://codeforces.com/edu/course/2/lesson/9/2
    @problem: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
    @time-complexity: O(log(n))  (!!not in amortization!!)
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
typedef	vector<int> vi;
typedef	vector<vi> vvi;
typedef	pair<int,int> pii;
typedef	pair<int,pii> pipii;
typedef	pair<pii,pii> piipii;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define all(a) a.begin(), a.end()

void Excalibur(){
    int n; cin >> n;
    ll s; cin >> s;
    vector<ll> A(n);
    for (auto &a: A) cin>>a;
    int r=0;
    ll su=0;
    int rs = INT_MIN;
    for(int i=0; i<n; ++i){
        while (r < n && su < s){
            su += A[r];
            ++r;
        }
        if (su <= s) {
            rs = max(rs, r-i);
        } else {
            rs = max(rs, r-i-1);
        }
        su -= A[i];
    }
    cout << rs;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
