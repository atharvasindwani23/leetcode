class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int idx = nums.size() - 1;
    vector<int> returner(nums.size());
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            std:: cout << "i enter here" << std::endl;
            returner[idx] = nums[left] * nums[left];
            std::cout << returner[right] << std::endl;
            left++;
        } else {
         returner[idx] = nums[right] * nums[right];
         right--;
        }
        idx--;
        std:: cout << left << std::endl;
        std::cout << right << std::endl;
    }
    return returner;
    }
};
