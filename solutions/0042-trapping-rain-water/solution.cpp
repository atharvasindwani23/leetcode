class Solution {
public:
    int trap(vector<int>& height) {
        int waterArea = 0;
        int l = 0;
        int r = height.size() - 1;
        if (height.size() == 0) {
            return 0;
        }
        int maxLeft = height[l];
        int maxRight = height[r];

        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                waterArea += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                waterArea += maxRight - height[r];
            }
        }
        return waterArea;
    }
};
