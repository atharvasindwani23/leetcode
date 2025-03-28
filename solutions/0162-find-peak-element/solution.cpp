class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int first = 0;
       int last = nums.size() - 1;
       if (nums.size() == 1) {
        return 0;
       }
       while (first < last) {
        int mid = (first + last) / 2;
        if (last - first == 1) {
            if (nums[first] > nums[last]) {
                return first;
            } else {
                return last;
            }
        }
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        if (nums[mid] <nums[mid + 1]) {
            first = mid + 1;
        } else if (nums[mid - 1] > nums[mid]) {
            last = mid - 1;
        }
       }
       if (first == last) {
        return first;
       }
       return 0;
    }

    // [1 2 3 1] -> 2
    // [1 2 1 3 5 6 4] -> 1/5
    // [1 2 .... inf .. 0] -> largest element will always be one of the peeks
    // [1 1 1 1 1 1 1] -> ? anything goes
    // [1 2 4 4 3 2] ->2/3
    // [1 2 1 3 5 6 4] -> 2, 6 
    // 1 -> 2 -> 1
    // 3 -> 5 -> 6 -> 4
     
};
