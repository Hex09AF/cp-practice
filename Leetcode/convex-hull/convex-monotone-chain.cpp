typedef	vector<vector<int>> vvi;
typedef	vector<int> vi;

int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    return (c[0] - b[0]) * (b[1]-a[1]) - (b[0] - a[0]) * (c[1] -b[1]);
}

int distance(const vector<int>& a, const vector<int>& b) {
    return (b[0]-a[0]) * (b[0]-a[0]) + (b[1]-a[1]) * (b[1]-a[1]);
}

class Solution {
public:
  vvi outerTrees(vvi& pt) {
    sort(pt.begin(), pt.end(), [](vi a, vi b) {
        return make_pair(a[0], a[1]) < make_pair(b[0], b[1]);
    });
    vi p1=pt[0], p2=pt.back();
    vvi up, down;
    up.push_back(p1);
    down.push_back(p1);

    for (int i=1; i<(int)pt.size(); ++i) {
        if (i == pt.size() - 1 || orientation(p1, pt[i], p2) >= 0) {
            while (up.size() >= 2 && orientation(up[up.size()-2], up[up.size()-1], pt[i]) < 0)
                up.pop_back();
            up.push_back(pt[i]);
        }
        if (i == pt.size() - 1 || orientation(p1, pt[i], p2) <= 0) {
            while (down.size() >= 2 && orientation(down[down.size()-2], down[down.size()-1], pt[i]) > 0)
                down.pop_back();
            down.push_back(pt[i]);
        }
    }

    if (up.size() == pt.size()) {
        reverse(pt.begin(), pt.end());
        return pt;
    }
    pt.clear();
    for (int i = 0; i < (int)up.size(); i++)
        pt.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        pt.push_back(down[i]);
    return pt;
  }
};
