class Solution {
public:
    int search(vector<int>& nums, int target) {
       int idx = largestElement(nums);
       std::cout << idx << std::endl;
       if (nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
       }
       int first = binarySearch(0, idx, nums, target);
       int second = binarySearch(idx + 1, nums.size() - 1, nums, target);
       if (first == -1) {
        std::cout << "meow?";
        return second;
       }  else {
        return first;
       }
    }
    //binary search ts
    //find largest element; then binary search twice [3 o(logn) operations]
    int largestElement(vector<int>& nums) {
    int lower = 0;
    int upper = nums.size() - 1;
    if (nums.size() == 1) return 0;
    if (nums[lower] < nums[upper]) return upper;

    while (lower <= upper) {
        int mid = (lower + upper) / 2;

        // Edge case: check neighbors carefully
        if (mid > 0 && mid < nums.size() - 1 &&
            nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
            return mid;
        }

        if (mid == 0 && nums[0] > nums[1]) return 0;
        if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) return mid;

        if (nums[lower] <= nums[mid]) {
            lower = mid + 1;
        } else {
            upper = mid - 1;
        }
    }
    return -90; // fallback
}

    int binarySearch(int lower, int upper, vector<int>& nums, int target) {
        int c = 0;
        while (lower <= upper) {
            c++;
            int mid = (lower + upper) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
            if (c > nums.size()) {
                return -1;
            }
        }
        return -1;
    }
};
