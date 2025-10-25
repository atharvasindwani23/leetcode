class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // Optimization: if k >= n/2, it's equivalent to unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }

        vector<vector<int>> ahead(k + 1, vector<int>(2, 0)), curr(k + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int t = 1; t <= k; t++) {
                // if we can buy
                curr[t][1] = max(-prices[i] + ahead[t][0], ahead[t][1]);
                // if we can sell
                curr[t][0] = max(prices[i] + ahead[t - 1][1], ahead[t][0]);
            }
            ahead = curr;
        }
        return ahead[k][1];
    }
};

