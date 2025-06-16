class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //literally same as best time to buy and sell stock, so just do it by that logic
        if (nums.size() == 1) {
            return nums[0];
        }
        int lower = 0;
        int upper = 1;
        int maxi = -1;
        while (upper < nums.size()) {
            if (nums[upper] > nums[lower]) {
                maxi = max(maxi, nums[upper] - nums[lower]);
            } else {
                lower = upper;
            }
            upper += 1;
        }
        return maxi;
    }
};
