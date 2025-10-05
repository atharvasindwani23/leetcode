class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unordered_map<int,int> freq;
        int max_count = 0;
        int count = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                max_count = max(max_count, count);
            } else {
                count = 0;
            }
        }
        return max_count;
    }
        //{0,1,3,4,5}
};
