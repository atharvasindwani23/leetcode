class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    std::map<int, int> values;
    for (unsigned int i = 0; i < nums.size(); i++) {
        values[nums[i]] = i; 
    }
    std::vector<int> returner;
    for (unsigned int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (values.find(complement) == values.end()) {
            values[nums[i]] = i;
        } else {
           returner.push_back(i);
           returner.push_back(values[target - nums[i]]);
           if (i == values[target - nums[i]]) {
            returner.clear();
            continue;
           }
           return returner;
        }   
    }
     return returner;
    }
};
