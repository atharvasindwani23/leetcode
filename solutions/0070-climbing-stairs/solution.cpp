class Solution {
public:
    int climbStairs(int n) {
        std::map<int,int> dp;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
