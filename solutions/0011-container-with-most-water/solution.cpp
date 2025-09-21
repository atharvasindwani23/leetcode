class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int lower = 0;
        int upper = height.size() - 1;
        while (lower < upper) {
            int h = min(height[lower], height[upper]);
            res = max(h * (upper - lower), res);
            if (height[lower] < height[upper]) {
                lower++;
            } else {
                upper--;
            }
        }
        return res;
    }
};
