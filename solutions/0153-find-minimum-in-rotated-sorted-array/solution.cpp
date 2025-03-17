class Solution {
public:
    int findMin(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[high]) {
            // Smallest element is on the right side
            low = mid + 1;
        } else {
            // Smallest element is on the left side or is mid itself
            high = mid;
        }
    }
    
    return nums[low];
    }
};
