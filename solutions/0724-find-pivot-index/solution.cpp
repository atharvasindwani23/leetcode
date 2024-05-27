class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (helper(0, i, nums) == helper(i + 1, nums.size(), nums)) {
                return i;
            }
        }
        return -1;
    }
    int helper(int start, int end,vector<int>& nums) {
        int sum = 0;
        for (unsigned int i = start; i < end; i++) {
           sum += nums[i];
        }
        return sum;
    }
};
