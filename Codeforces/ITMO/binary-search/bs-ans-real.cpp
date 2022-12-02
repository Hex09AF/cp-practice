/*
    @lesson: https://codeforces.com/edu/course/2/lesson/6/2
    @problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
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

int n, k;
vector<double> A;

bool good(double m) {
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        cnt += floor(A[i] / m);
    }
    return cnt >= k;
}

void Excalibur(){
    cin >> n >> k;
    A.resize(n);
    for (auto&v: A) cin >> v;
    double l = 0, r = 1e7;

    for (int i=0; i<100; ++i) {
        double m = (r + l) / 2;
        if (good(m)) {
            l = m;
        } else { 
            r = m;
        }
    }

    cout << setprecision(20) << r;
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
