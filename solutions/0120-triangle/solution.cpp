class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = { triangle[0][0] };                 // row 0 has 1 element

        for (int i = 1; i < n; ++i) {
            int m = (int)triangle[i].size();
            dp[i].resize(m);
            for (int j = 0; j < m; ++j) {
                if (j == 0) { // from directly above-left doesn't exist
                    dp[i][j] = dp[i - 1][0] + triangle[i][j];
                } else if (j == m - 1) { // from directly above doesn't exist
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        int ans = dp[n - 1][0];
        for (int v : dp[n - 1]) ans = std::min(ans, v);
        return ans;
    }
};

