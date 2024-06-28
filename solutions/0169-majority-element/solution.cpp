class Solution {
public:
    int majorityElement(vector<int>& nums) {
       std::map<int,int> num_freq;
       for (int i  : nums) {
        if (!num_freq.contains(i)) {
        num_freq[i] = 1;
        } else {
            num_freq[i]++;
        }
       }
       for (int i : nums) {
        if (num_freq[i] > nums.size() / 2) {
            return i;
        }
       }
       return 0;
    }
};
