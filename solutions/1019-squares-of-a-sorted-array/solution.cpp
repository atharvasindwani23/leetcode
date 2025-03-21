class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>returner(nums.size());
        int start = 0;
        int end = nums.size() - 1;
        int idx = nums.size() - 1;
        while (start <= end) {
            if (nums[start] * nums[start] < nums[end] * nums[end]) {
                returner[idx] = nums[end] * nums[end];
                end--;
            } else {
                returner[idx] = nums[start] * nums[start];
                start++;
            }
            idx--;
        }
        return returner;
    }
};
