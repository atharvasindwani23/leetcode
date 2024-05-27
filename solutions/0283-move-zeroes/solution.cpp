class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::vector<int> returner;
        int c = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
             if (nums[i] != 0) {
                c++;
                returner.push_back(nums[i]);
             }
        }
        for (unsigned int i = 0; i < nums.size() - c; i++) {
            returner.push_back(0);
        }
        std::cout << c;
        nums = returner;
    }
};
