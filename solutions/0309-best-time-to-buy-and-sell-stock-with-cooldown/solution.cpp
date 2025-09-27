class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //false represents can buy 
        //true represents can sell
        //wanna return dp[0][0]
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n - 1][1] = prices[n - 1];
        dp[n - 1][0] = 0;
        dp[n][0] = 0;

        for (int i  = n - 2; i >= 0; i--) {
            dp[i][1] = max(dp[i + 1][1], dp[i + 2][0] + prices[i]);
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - prices[i]);
        }
        return dp[0][0];
    }

    //result to be stored in dp[0][true]
};
