/*
    @lesson: https://codeforces.com/edu/course/2/lesson/4/3
    @problem: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
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
    if (r <= ql || l >= qr) return NEUTRAL_ELEMENT;
    if (l >= ql && r <= qr) return SEG[idx];
    int m = (l + r) >> 1;
    return merge(query(l, m, ql, qr, idx << 1), query(m, r, ql, qr, idx << 1 | 1));
}

item querySeg(int ql, int qr) {
    return query(0, n, ql, qr, 1);
}

void updateOne(int i, int v) {
    update(0, n, i, v, 1);
}

void Excalibur(){
    cin >> n; n *= 2;
    A.resize(n);
    SEG.resize(n * 4);
    for (int &v: A) v = 0;
    build(0, n, 1);

    vector<int> B(n/2);
    unordered_map<int,int> um;

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (um.find(x) != um.end()) {
            B[x-1] = querySeg(um[x], i+1);
            updateOne(i, 1);
            updateOne(um[x], -1);
        } else {
            um[x] = i;
            updateOne(um[x], 1);
        }
    }

    for (auto x: B) cout << x - 1 << " ";
}

int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
