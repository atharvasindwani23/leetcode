class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        

        sort(nums.begin(), nums.end());
        // 100,4,200,1,3,2 => 1,2,3,4,100,200
        //0,0,1,1,2,2,2,3,4
        std::map<int,bool> present;
        std::vector<int> newVec;
        for (int i = 0; i < nums.size(); i++) {
            if (!present[nums[i]]) {
                present[nums[i]] = true;
                newVec.push_back(nums[i]);
            }
        }
        
        int longest = 1;
        int maximum = 1;
        int lower = 0;
        int upper = 1;
        while (upper < newVec.size()) {
            if (newVec[upper] - newVec[lower] == upper - lower) {
                upper++;
                longest++;
            } else {
                maximum = max(maximum, longest);
                lower = upper;
                upper++;
                longest = 1;
            }
        }
    
        return max(maximum, longest);
    }
};
