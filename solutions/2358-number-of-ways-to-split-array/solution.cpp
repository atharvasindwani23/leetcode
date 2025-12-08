class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long totalSum = 0;

       for (int num : nums) {
        totalSum += num;
       } 
       long runningSum = 0;
        int count = 0;
       for (int i = 0; i < nums.size() - 1; i++) {
            runningSum = runningSum + nums[i];
            if (runningSum * 2 >= totalSum) {
                cout << i << endl;
                count++;
            }
       }
       return count;
    }

};
