/*
    @lesson: https://codeforces.com/edu/course/2/lesson/2/3
    @problem: https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
    @time-complexity: O(nlog^2(n)) 
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

void radix_sort(vector<pair<pair<int,int>, int> > &A) {
{    
    int n = A.size();
    vector<int> cnt(n, 0);
    for (auto v: A) {
        cnt[v.first.second]++;
    }
    vector<pair<pair<int,int>, int> > NewA(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i=1; i<n; ++i) {
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for (auto v: A) {
        int i = v.first.second;
        NewA[pos[i]] = v;
        pos[i]++;
    }
    A = NewA;
}
{
    int n = A.size();
    vector<int> cnt(n, 0);
    for (auto v: A) {
        cnt[v.first.first]++;
    }
    vector<pair<pair<int,int>, int> > NewA(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i=1; i<n; ++i) {
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for (auto v: A) {
        int i = v.first.first;
        NewA[pos[i]] = v;
        pos[i]++;
    }
    A = NewA;
}
}

void Excalibur(){
    string s; cin >> s;
    s.push_back('$');
    int n = s.size();
    vector<pair<char,int> > Init(n);
    for (int i=0; i<n; ++i) {
        Init[i] = { s[i], i };
    }
    sort(Init.begin(), Init.end());

    vector<int> C(n);
    C[Init[0].second] = 0;

    for (int i=1; i<n; ++i) {
        C[Init[i].second] = C[Init[i-1].second];
        if (Init[i].first != Init[i-1].first) {
            C[Init[i].second] += 1;
        }
    }

    int k = 0;
    vector<pair<pair<int,int>, int> > P(n);
    while ((1 << k) < n) {
        for (int i=0; i<n; ++i) {
            P[i] = {{C[i], C[(i + (1<<k))%n]}, i};
        }
        radix_sort(P);

        C[P[0].second] = 0;
        for (int i=1; i<n; ++i) {
            C[P[i].second] = C[P[i-1].second];
            if (P[i].first != P[i-1].first) {
                C[P[i].second] += 1;
            }
        }
        
        ++k;
    }

    int q; cin >> q;
    for (int i=0; i<q; ++i) {
        string st; cin >> st;
        int l=0, r=n-1;
        while (l <= r) {
            int m = r - ((r-l)>>1);
            string substr = s.substr(P[m].second, st.size());
            int comp = st > substr ? 1 : - 1;
            if (comp == 1) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (l >= 0 && l<n && s.substr(P[l].second, st.size()) == st) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
 
int main(){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int tc = 1; while (tc--) Excalibur(); return 0;}
