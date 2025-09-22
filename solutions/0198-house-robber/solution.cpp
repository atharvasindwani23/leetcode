class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size + 1, 0);
        dp[size] = 0;
        dp[size - 1] = nums[size - 1];
        for (int i  = size - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};
