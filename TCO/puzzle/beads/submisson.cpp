/*
    @problem: https://www.topcoder.com/challenges/c01e67de-2902-44cc-8464-df592db532a6?tab=details
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
#include <fstream>

using namespace std;
#define DB(x) 	cerr << #x << " is " << (x) << "\n";
typedef long long	ll;
typedef	long double ld;
const int mxn = 1e4;
const ll mod = 998244353;
const ll oo = 1e12+7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

/*
    red:    1
    green:  2
    blue:   3
    cyan:   4
    pink:   5
*/
vector<vector<int> > A = {
    {0,0,0,0,0,0},
    {0,4,3,2,1,5},
    {0,3,2,1,5,4},
    {0,2,1,5,4,3},
    {0,1,5,4,3,2}
};
map<string, int> MM;
vector<string> M = {
    "",
    "red",
    "green",
    "blue",
    "cyan",
    "pink"
};
void print() {
    for (auto V: A) {
        for (auto c: V) cout << c << " ";
        cout << "\n";
    }
}
void write(int a, int b, int c, ofstream& o) {
    o << M[a] << " " << M[b] << " " << c << endl;
} 

void Excalibur(){
    ofstream o;
    o.open("output.out");
    MM["red"] = 1;
    MM["green"] = 2;
    MM["blue"] = 3;
    MM["cyan"] = 4;
    MM["pink"] = 5;
    while (true) {
        print();
        int c;
        string u, v; cin >> u >> v >> c;
        // int a, b; cin >> a >> b >> c;
        int a = MM[u], b = MM[v];
        // if (a == 0 || b == 0 || c == 0) break;
        // write(a, b, c, o);        

        queue<int> q;
        for (int i=0; i<A.size() && q.size()<c; ++i){
            if (A[i][a]) {
                q.push(A[i][a]);
                A[i][a] = 0;
            };
        }
        for (int i=A.size()-1; i >= 0 && !q.empty(); --i) {
            if (!A[i][b]) {
                A[i][b] = q.front();
                q.pop();
            }
        }
    }
    o.close();
}

int main(){ios::sync_with_stdio(false); cin.tie(NULL);
Excalibur(); return 0;}
