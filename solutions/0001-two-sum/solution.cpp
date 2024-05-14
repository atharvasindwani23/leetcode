class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returner;
        for (unsigned int i  = 0;  i < nums.size(); i++) {
            for (unsigned int j = 0; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target &&  i < j) {
             returner.push_back(i);
             returner.push_back(j);
            }
            }
        }
        return returner;
    }
};
