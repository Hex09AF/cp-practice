int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    return (c[0] - b[0]) * (b[1]-a[1]) - (b[0] - a[0]) * (c[1] -b[1]);
}

int distance(const vector<int>& a, const vector<int>& b) {
    return (b[0]-a[0]) * (b[0]-a[0]) + (b[1]-a[1]) * (b[1]-a[1]);
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<int> p0 = trees[0];
        for (auto v: trees) {
            if (p0[1] > v[1]) {
                p0 = v;
            } else if (p0[1] == v[1] && p0[1] > v[0]) {
                p0 = v;
            }
        }
        
        sort(trees.begin(), trees.end(), [&p0](const vector<int>& a, const vector<int>& b) {
            int o = orientation(p0, a, b);
            if (o == 0) return distance(p0,a) < distance(p0,b);
            return o > 0;
        });

        int i = (int)trees.size()-1;
        while (i >= 0 && orientation(p0, trees[i], trees.back()) == 0) i--;
        reverse(trees.begin()+i+1, trees.end());

        vector<vector<int> > st;
    
        for (int i=0; i<trees.size(); ++i) {
            while (st.size() > 1 && orientation(st[st.size()-2], st.back(), trees[i]) < 0) {
                cout << st.back()[0] << " " << st.back()[1] << "\n";
                st.pop_back();
            }
            st.push_back(trees[i]);
        }

        return st;
    }
};