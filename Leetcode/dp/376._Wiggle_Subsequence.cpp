class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        int n = A.size();
        vector<int> POS(n, 0), NEG(n, 0);
        int rs = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (A[i] - A[j] > 0) {
                    POS[i] = max(POS[i], NEG[j] + 1);
                }
                if (A[i] - A[j] < 0) {
                    NEG[i] = max(NEG[i], POS[j] + 1);
                }
            }
            rs = max({rs, POS[i], NEG[i]});
        }
        return rs + 1;
    }
};