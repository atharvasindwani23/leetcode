class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int returner = 0;
    int count = 0;
    if (nums.size() == 0) {
        return 0;
    }
    std::sort(nums.begin(), nums.end());
    for (unsigned int i = 1; i < nums.size(); i++) {
       if (nums[i] - nums[i - 1] == 1) {
        count++;
       } else {
        if (nums[i] - nums[i -1] == 0) {
            ;
        } else {
        returner = std::max(returner, count);
        count = 0;
        }
       }   
    }
    returner = std::max(returner, count);
    return returner + 1;
    }
};
