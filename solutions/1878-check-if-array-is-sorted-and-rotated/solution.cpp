class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> copy;
        int pivot = nums.size();
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i + 1;
            }   
        }
        for (int i = pivot; i < nums.size(); i++) {
            copy.push_back(nums[i]);
        }
        for (int i = 0; i < pivot; i++) {
            copy.push_back(nums[i]);
        }
        for (int i = 0; i < copy.size() - 1; i++) {
        if (copy[i] > copy[i + 1]) {
            return false;
        }
    }
     return true;
    }
};
