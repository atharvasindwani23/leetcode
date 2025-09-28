class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minimum = INT_MAX;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];  // Expand the window
        
        while (sum >= target) {  // Shrink the window
            minimum = min(minimum, right - left + 1);
            sum -= nums[left++];
        }
    }
    
    return (minimum == INT_MAX) ? 0 : minimum;
}

};
