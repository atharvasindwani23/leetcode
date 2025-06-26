class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        std::map<int,bool> present;
        for (int i = 0; i < len; i++) {
            present[nums[i]] = true;
        }
        for (int i = 1; i <= len; i++) {
            if (!present[i]) {
                return i;
            }
        }
        return len + 1;
    }
};
