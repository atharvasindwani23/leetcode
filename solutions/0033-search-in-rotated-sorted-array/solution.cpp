class Solution {
public:
    int search(vector<int>& nums, int target) {
    int magic_index = 0;
     int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }    
    magic_index = low - 1;
    int idx_first = binarySearch(0, magic_index, nums, target);
    int idx_second = binarySearch(magic_index + 1, nums.size() - 1, nums, target);
    if (idx_first == -1 && idx_second == -1) {
        return -1;
    } else {
        if (idx_first == -1) {
            return idx_second;
        }
        return idx_first;
    }
}
    int binarySearch(int l, int r, vector<int> nums, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
