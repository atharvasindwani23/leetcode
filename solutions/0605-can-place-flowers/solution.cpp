class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> dp(flowerbed.size() + 1, 0);
         int len = flowerbed.size();
         dp[len] = 0;
         if (flowerbed[len - 1] == 0) {
            dp[len - 1] = 1;
         } else {
            dp[len - 1] = 0; 
         }
         for (int i = len - 2; i >= 0; i--) {
            if (flowerbed[i] == 1) {
                dp[i] = dp[i + 2];
            } else {
                if (flowerbed[i + 1] == 1) {
                    dp[i] = dp[i + 1];
                } else {
                    dp[i] = dp[i + 2] + 1;
                }
            }
         }
         return dp[0] >= n;
    }
};
