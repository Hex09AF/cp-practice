class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int cnt = 0;
        int n = coins.size();
        vector<int> A(amount+1, 0);
        A[0] = 1;
        for (int j=0; j<n; ++j) {
            for (int i=1; i<=amount; ++i) {
                if (i-coins[j] >= 0) {
                    A[i] += A[i-coins[j]];
                }
            }
        }
        return A[amount];
    }
};