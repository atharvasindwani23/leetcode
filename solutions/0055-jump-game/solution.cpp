class Solution {
public:
    bool canJump(vector<int>& nums) {
      int x = 0;
      for (int i = 0; i <= x; i++) {
        x = std::max(x, i + nums[i]);
        if (x >= nums.size() - 1) {
            return true;
        }
      }
    //i + nums[i] >= nums.size() - 1;
    return false;
    }
};
