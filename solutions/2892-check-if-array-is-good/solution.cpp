class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }   
        for (int i = 1; i <= freq.size() - 1; i++) {
            if (!freq.count(i) || freq[i] > 1) {
                return false;
            }
        }
        return freq[freq.size()] == 2;
    }
};
