class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> zeroes;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                c++;
                continue;
            }
            zeroes.push_back(nums[i]);
        }
        for (int i = 0; i < c; i++) {
            zeroes.push_back(0);
        }
        nums = zeroes;
    }
};
