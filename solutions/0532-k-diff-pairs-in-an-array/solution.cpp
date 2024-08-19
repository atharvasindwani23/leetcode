class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int start = 0;
    int end = 1;
    int count = 0;
    while (end < nums.size() && start < nums.size()) {
        if (nums[end] - nums[start] < k) {
            end++;
        } else if (nums[end] - nums[start] == k && (start != end)) {
           count++;
            while (start < nums.size() - 1 && nums[start] == nums[start + 1]) {
                start++;
            }
            while(end < nums.size() - 1 && nums[end] == nums[end + 1]) {
                end++;
           }
           end++;
           start++;
        } else {
            start++;
        }
    }
    return count;
    }
};
