class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev_increase = 0, cur_increase = 1;
        int longest_k = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                cur_increase += 1;
            } else {
                prev_increase = cur_increase;
                cur_increase = 1;
            }
            longest_k = max(longest_k, max(cur_increase / 2, min(prev_increase, cur_increase))); 
        }
        return longest_k >= k;
    }
};
