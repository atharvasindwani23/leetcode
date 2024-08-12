class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
     int count = 0;
    std::sort(nums.begin(), nums.end());
    int start = 0;
    int end = 1;
    while (end < nums.size() && start < nums.size()) {
     if (k == 0) {
       if (nums[end] - nums[start] > k) {
        start++;
     } else {
        start++;
        end++;
        count++;
        if (end == nums.size() - 1 || start == nums.size() - 1) {
           return count;
        }
        std::cout <<"problem stems here" << std::endl;
        while (end < nums.size() && nums[end] == nums[end - 1]) {
            std::cout <<"problem here" << std::endl;
            end++;
        }
     }
     }
     if (nums[end] - nums[start] < k) {
        end++;
     }
     if (nums[end] - nums[start] > k) {
        start++;
     }
     if (nums[end] - nums[start] == k) {
        if (start == end) {
            end++;
        } else {
        start++;
        end++;
        count++;
        while (end != nums.size() && nums[end] == nums[end - 1]) {
            end++;
        }
        }
     }
    }
    return count;
    }
};
