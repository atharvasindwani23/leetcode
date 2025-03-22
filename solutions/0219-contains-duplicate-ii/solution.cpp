class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::set<int>unique;
        for (int i = 0; i < nums.size(); i++) {
            if (unique.contains(nums[i])) {
                return true;
            } else {
                unique.insert(nums[i]);
                if (unique.size() > k) {
                    unique.erase(nums[i - k]);
                }
            }
        }
        return false;
    }
};
