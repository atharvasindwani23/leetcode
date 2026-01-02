class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       unordered_set<int> unique;
       for (int num : nums) {
        if (unique.count(num)) {
            return num;
        }
        unique.insert(num);
       }
       return -1;
    }
};
