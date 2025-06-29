class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            }
            return -1;
        }
        int pivot = largestIdx(nums);
        std::cout << pivot << std::endl;
        int left = binary(0, pivot, nums, target);
        int right = binary(pivot + 1, nums.size() - 1, nums, target);
        if (left == -1) {
            return right;
        }
        return left;
    }
    int largestIdx(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1]) {
            return nums.size() - 1;
        }
        int lower = 0;
        int upper = nums.size() - 1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (mid == 0) {
                std::cout << nums.size() << std::endl;
                if (nums[0] < nums[1]) {
                    return 1;
                }
                return 0;
            }
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            }
            //[][][][][]
            if (nums[lower] <= nums[mid]) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        std::cout << "meow?" << std::endl;
        return -1;
    }
    int binary(int left, int right, vector<int>& nums, int target) {
        int lower = left;
        int upper = right;
        int c = 0;
        while (lower <= upper) {
            c++;
            int mid = (lower + upper) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
            if (c > nums.size()) {
                return -1;
            }
        }
        return -1;
    }
};
