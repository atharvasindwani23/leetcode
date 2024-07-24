class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::map<int,int> freq;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(freq[nums[i]] > 1) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == nums[i]) {
                        nums[j] = 101;
                    }
                }
            } 
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 101) {
                count++;
            }
        }
              std::sort(nums.begin(), nums.end());
              std::cout << nums.size() - count;
          return count;

    }
};
