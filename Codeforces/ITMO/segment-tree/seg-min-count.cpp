/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/1
    @problem: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
    @time-complexity: O(nlogn) (build)
        Operation set: O(logn)
        Operation sum / min: O(logn)
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
vector<ll> A;
vector<pair<int,int> > SEG;

pair<int,int> merg(pair<int,int> left, pair<int,int> right) {
    if (left.first < right.first) {
        return left;
    } else if (left.first > right.first) {
        return right;
    } 
    return {left.first, left.second + right.second};
}

pair<int,int> build(int l, int r, int idx) {
    if (r - l == 1) {
        SEG[idx] = {A[l], 1};
    } else {
        int m = (r + l) >> 1;
        SEG[idx] = merg(build(l, m, idx << 1), build(m, r, idx << 1 | 1));
    }
    return SEG[idx];
}

void update(int l, int r, int i, int v, int idx) {
    if (r - l == 1) {
        SEG[idx] = {v, 1};
        return;
    }
    int m = (r + l) >> 1;
    if (i < m) {
        update(l, m, i, v, idx << 1);
    } else {
        update(m, r, i, v, idx << 1 | 1);
    }
    SEG[idx] = merg(SEG[idx << 1], SEG[idx << 1 | 1]);
}

pair<int,int> query(int l, int r, int ql, int qr, int idx) {
    if (l >= qr || r <= ql) return {INT_MAX, 0};
    if (l >= ql && r <= qr) return SEG[idx];
    int m = (r + l) >> 1;
    return merg(query(l, m, ql, qr, idx << 1), query(m, r, ql, qr, idx << 1 | 1));
}

void Excalibur(){
    int n, m; cin >> n >> m;
    A.resize(n);
    SEG.resize(n * 4);
    for (ll &v: A) cin >> v;
    build(0, n, 1);
    while (m--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 1) {
            A[y] = z;
            update(0, n, y, z, 1);
        } else {
            pair<int,int> ans = query(0, n, y, z, 1);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
