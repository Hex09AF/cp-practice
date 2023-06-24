class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        set<pair<int,int>> l;
        unordered_map<int,int> ll;
        set<pair<int,int>> r;
        unordered_map<int,int> rr;
        int rs = 0;
        int n = rods.size();
        int m = n >> 1;

        l.insert({0,0});
        for (int i=0; i<m; ++i) {
            set<pair<int,int>> cur(l);
            int x = rods[i];
            for (auto it: cur) {
                l.insert({it.first+x,it.second});
                l.insert({it.first,it.second+x});
            }
        }
        r.insert({0,0});
        for (int i=m; i<n; ++i) {
            set<pair<int,int>> cur(r);
            int x = rods[i];
            for (auto it: cur) {
                r.insert({it.first+x,it.second});
                r.insert({it.first,it.second+x});
            }
        }
       
        for (auto it: l) {
            int d = it.first - it.second;
            ll[d] = max(ll[d], it.first);
        }
        for (auto it: r) {
            int d = it.first - it.second;
            rr[d] = max(rr[d], it.first);
        }

        for (auto it: ll) {
            if (rr.find(-it.first) != rr.end()) {
                rs = max(rs, rr[-it.first] + it.second);
            }
        }
        return rs;
    }
};
