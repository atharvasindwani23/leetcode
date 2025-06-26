class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i  = 0; i < nums.size(); i++) {
            std::cout << helper(nums, 0 , i) << std::endl;
            std::cout << helper(nums, i + 1, nums.size()) << std::endl;
            if (helper(nums,0, i) == helper(nums, i + 1, nums.size())) {
                return i;
            }
        }
        return -1;
    }
    int helper(vector<int>&nums, int lower, int upper) {
        int returner = 0;
        for (int i = lower; i < upper; i++) {
            returner += nums[i];
        }
        return returner;
    }
};
