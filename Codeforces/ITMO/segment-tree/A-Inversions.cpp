/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/3
    @problem: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
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

item query(int l, int r, int ql, int qr, int idx) {
    if (l >= qr || r <= ql) return NEUTRAL_ELEMENT;
    if (l >= ql && r <= qr) return SEG[idx];
    int m = (r + l) >> 1;
    return merge(query(l, m, ql, qr, idx << 1), query(m, r, ql, qr, idx << 1 | 1));
}

void updateOne(int i, int v) {
    update(0, n, i, v, 1);
}

item querySeg(int ql, int qr) {
    return query(0, n, ql, qr, 1);
}

void Excalibur(){
    cin >> n;
    A.resize(n);
    SEG.resize(n * 4);
    for (int &v: A) v = 0;
    build(0, n, 1);

    m = n;
    while (m--) {
        int x; cin >> x;
        cout << querySeg(x-1, n) << " ";
        updateOne(x-1, 1);
    }
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}

/**
 * 4 -> 0 0 0 1 0;
 * 1 -> 1 0 0 1 0;
 * 3 -> 1 0 1 1 0;
*/