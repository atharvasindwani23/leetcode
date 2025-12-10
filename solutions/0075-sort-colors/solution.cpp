class Solution {
public:
    void sortColors(vector<int>& nums) {
        //use a map and do it in o(n) space and time
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < count[0]) {
                nums[i] = 0;
            } else if (i < count[1] + count[0]) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }
};
