class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i  = nums.size() - 1; i >= 2; i--) {
            if (isTriangle(nums[i - 2], nums[i - 1], nums[i])) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
    bool isTriangle(int a, int b, int c) {
        return (a + b > c);
    }

    //we have to first verify if it can form a triangle
    //
};
