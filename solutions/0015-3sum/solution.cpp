class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> returner;
        std::sort(nums.begin(), nums.end());
        
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicate values for the first element
            }
            
            int first = i + 1;
            int last = nums.size() - 1;
            
            while (first < last) {
                int sum = nums[i] + nums[first] + nums[last];
                
                if (sum == 0) {
                    returner.push_back({nums[i], nums[first], nums[last]});
                    ++first;
                    --last;
                    
                    // Skip duplicate values for the second and third elements
                    while (first < last && nums[first] == nums[first - 1]) {
                        ++first;
                    }
                    while (first < last && nums[last] == nums[last + 1]) {
                        --last;
                    }
                } else if (sum > 0) {
                    --last;
                } else {
                    ++first;
                }
            }
        }
        
        return returner;
    }
};
