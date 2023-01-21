class Solution {
public:
    int combinationSum4(vector<int>& A, int v) {
        int n = A.size();
        vector<unsigned long long> DP(v+1, 0);
        DP[0] = 1;
        for (int j=1; j<=v; ++j) {
            for (int i=0; i<n; ++i) {
                if (j - A[i] >= 0) {
                    DP[j] += DP[j - A[i]];
                }
            }
        }
        return DP[v];
    }
};