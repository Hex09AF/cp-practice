class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ls;
        int l = 0;
        for (int i=0; i<nums.size(); ++i) {
            auto it = lower_bound(ls.begin(), ls.end(), nums[i]);
            if (it == ls.end()) {
                ls.push_back(nums[i]);
            } else {
                ls[it-ls.begin()] = nums[i];
            }
        }
        return ls.size();
    }
};