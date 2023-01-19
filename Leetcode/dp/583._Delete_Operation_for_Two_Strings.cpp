class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return dis(a, b, n, m);
    }
    int dis(string a, string b, int n, int m) {
        if (n == -1) return m + 1;
        if (m == -1) return n + 1;
        if (dp[n][m] != -1) return dp[n][m];
        if (a[n] == b[m]) return dp[n][m] = min({
            dis(a, b, n, m-1) + 1,
            dis(a, b, n-1, m) + 1,
            dis(a, b, n-1, m-1)});
        return dp[n][m] = min({dis(a, b, n, m-1) + 1, dis(a, b, n-1, m) + 1});
    }
};