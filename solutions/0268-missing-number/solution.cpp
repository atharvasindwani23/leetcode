class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::map<int,int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        for (int i = 0; i <= nums.size(); i++) {
            if (freq[i] == 0) {
                return i;
            }
        }
        return -1;
    } 
};

