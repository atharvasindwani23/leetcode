class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> store;
        vector<int> res;
        //create a map of differences -> map[sum - arr[i]] = i
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (store.count(diff) == 0) {
                store[nums[i]] = i;
            } else {
                res.push_back(i);
                res.push_back(store[diff]);
                return res;
            }
        }
        return {};
    }
};
