/*
    @lesson: https://codeforces.com/edu/course/2/lesson/9/1
    @problem: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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
    vector<int> A(n), B(m), C(n+m);
    for (int &v: A) cin >> v;
    for (int &v: B) cin >> v;
    int i=0, j=0;
    while (i+j < n+m) {
        if (i < n && j < m) {
            if (A[i] <= B[j]) {
                C[i+j] = A[i];
                ++i;
            } else {
                C[i+j] = B[j];
                ++j;
            }
        } else if (i == n) C[i+j] = B[j], ++j;
        else C[i+j] = A[i], ++i;
    }
    for (int v: C) cout << v << " ";
}

int main(){ios::sync_with_stdio(false); 
Excalibur();return 0;}