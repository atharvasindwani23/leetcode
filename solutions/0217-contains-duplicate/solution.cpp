class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (unsigned int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] == 0) {
                return true;
            }
        }
        return false;
    }
};


// [1 2 3 1] => true
// [1 2 1 2] => true
// [] => false
// looping over twice -> arr[i] == arr[j] where our i != j; -> BRUTE FORCE SOLUTION 
// O(n^2) time
// hashMap of some sort -> .count() > 1 -> return true, O(n) solution

