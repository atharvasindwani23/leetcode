class Solution {
public:
    int rob(vector<int>& nums) {
     
      std::map<int,int>dp;
      if (nums.size() == 1) {
        return nums[0];
      }
      dp[0] = nums[0];
      dp[1] = std::max(nums[1], nums[0]);
      for (unsigned int i = 2; i < nums.size(); i++) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
      }
      return dp[nums.size() - 1];  
    }
};
