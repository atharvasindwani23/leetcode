class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std:: map<int, int> num_count;
        for (unsigned int i = 0; i < nums.size(); i++) {
             if (num_count.contains(nums[i])) {
                num_count[nums[i]] = 2;
             } else {
                num_count[nums[i]] = 1;
             }
        }
        for (int num : nums) {
            if (num_count[num] == 1) {
                return num;
            }
        }
        return -1;
    }

};
