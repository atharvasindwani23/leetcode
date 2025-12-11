class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long runningSum = 0;
        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            runningSum += nums[i];
            if (runningSum >= totalSum - runningSum) {
                count++;
            }
        }
        return count;
    }
};
