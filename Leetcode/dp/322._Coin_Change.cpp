typedef vector<int> vi;
class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vi dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=amount; ++i) {
            for (int j=0; j<n; ++j) {
                if (i - a[j] >= 0 && dp[i-a[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-a[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};