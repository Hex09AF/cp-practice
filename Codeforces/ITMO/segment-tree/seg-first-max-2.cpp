/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/2
    @problem: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
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
item NEUTRAL_ELEMENT = 0;

vector<int> A;
vector<item> SEG;

item single(int v) {
    return v;
}

item merge(item a, item b) {
    return max(a , b);
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

item find(int k, int idx, int l, int r, int leftmost) {
    if (SEG[idx] < k) return -1;
    if (r <= leftmost) return -1;
    if (r - l == 1) return l;
    int m = (r + l) >> 1;
    int lres = find(k, idx << 1, l, m, leftmost);
    if (lres == -1) {
        lres = find(k, idx << 1 | 1, m, r, leftmost);
    }
    return lres;
}

void Excalibur(){
    int n, m; cin >> n >> m;
    A.resize(n);
    SEG.resize(n * 4);
    for (int &v: A) cin >> v;
    build(0, n, 1);
    while (m--) {
        int op; cin >> op;
        int x, y;
        cin >> x >> y;
        if (op == 1) {
            A[x] = y;
            update(0, n, x, y, 1);
        } else {
            cout << find(x, 1, 0, n, y) << "\n";
        }
    }
}

int main(){ios::sync_with_stdio(false); 
Excalibur(); return 0;}
