class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        if (n < 3) return 0;

        int res = 0;
        for (int i = n - 1; i >= 2; --i) {   // nums[i] is the largest side
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += (r - l);  // all l..r-1 work with this r
                    --r;             // shrink r to look for more
                } else {
                    ++l;             // need a bigger left to increase sum
                }
            }
        }
        return res;
    }
};

