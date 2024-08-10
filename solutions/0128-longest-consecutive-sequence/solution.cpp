class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      std::sort(nums.begin(), nums.end());
      if (nums.size() == 0) {
        return 0;
      }
      //std::cout << nums.at(0);
      int count = 0;
      int max = 0;
      for (unsigned int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] - nums[i] == 1) {
            count++;
        } else {
            if (nums[i + 1] - nums[i] == 0) {
               
            } else {
            max = std::max(max, count);
            count = 0;
            }
        }
      max = std::max(max, count);
      }
      return max + 1;
    }
};
