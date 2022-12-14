/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/3
    @problem: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
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
typedef int item;

int n, m;
item NEUTRAL_ELEMENT = 0;
vector<int> A;
vector<item> SEG;

item single(int v) {
    return v;
}

item merge(item a, item b) {
    return a + b;
}

void build(int l, int r, int idx) {
    if (r - l == 1) {
        SEG[idx] = single(A[l]);
        return;
    } 
    int m = (r + l) >> 1;
    build(l, m, idx << 1);
    build(m, r, idx << 1 | 1);
    SEG[idx] = merge(SEG[idx << 1], SEG[idx << 1 | 1]);
}

void update(int l, int r, int i, int v, int idx) {
    if (r - l == 1) {
        SEG[idx] = single(v);
        return;
    }
    int m = (r + l) >> 1;
    if (i < m) {
        update(l, m, i, v, idx << 1);
    } else {
        update(m, r, i, v, idx << 1 | 1);
    }
    SEG[idx] = merge(SEG[idx << 1], SEG[idx << 1 | 1]);
}

int find(int k, int idx, int l, int r ) {
    if (r - l == 1) return l;
    int m = (l+r)>>1;
    int sl = SEG[idx << 1 | 1];
    if (k < sl) {
        return find(k, idx << 1 | 1, m, r);
    } else {
        return find(k - sl, idx << 1, l, m);
    }
}

void updateOne(int i, int v) {
    update(0, n, i, v, 1);
}

void Excalibur(){
    cin >> n;
    A.resize(n);
    SEG.resize(n * 4);
    for (int &v: A) v = 1;
    build(0, n, 1);

    vector<int> B(n);
    for (int i=0; i<n; ++i) cin >> B[i];

    for (int i=n-1; i>=0; --i) {
        int idx = find(B[i], 1, 0, n);
        A[i] = idx+1;
        updateOne(idx, 0);
    }
    for (auto x: A) cout << x << " ";
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
