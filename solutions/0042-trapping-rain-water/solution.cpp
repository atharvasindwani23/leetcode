class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int sum = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                maxL = max(maxL, height[l]);
                sum += (maxL - height[l]);
            } else {
                r--;
                maxR = max(maxR, height[r]);
                sum += (maxR - height[r]);
            }
        }
        return sum;
    }
};
