class Solution {
public:
    int triangularSum(vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        dp[0] = nums;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % 10;
            }
        }
        if (dp.size() > 1) {
        for (int ele : dp[1]) {
            cout << ele << endl;
        }
        }

        return dp[nums.size() - 1][0];
    }
};
