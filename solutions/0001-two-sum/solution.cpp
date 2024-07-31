class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returner;
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = i + 1; j < nums.size(); j++) {
                if (target == nums[j] + nums[i]) {
                    returner.push_back(i);
                    returner.push_back(j);
                }
            }
        }
        return returner;
    }
};
