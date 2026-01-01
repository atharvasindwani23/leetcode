class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (j == 0) {
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                    continue;
                } if (j == matrix.size() - 1) {
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                    continue;
                }
                dp[i][j] = matrix[i][j] + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            res = min(res, dp[matrix.size() - 1][i]);
        }
        return res;
    }

    //dp[i][j] store the minimum path sum it took to get there
    //dp[i][j] = matrix[i][j] + min(dp[i - 1][j] + dp[i - 1][j - 1], dp[i - 1][j + 1])

    //at the end we can just do a quick o(n) scan and conclude. 

    //can start from anywhere in the top row; then has to go either down; down right; down left.

    //djikstras?
};
