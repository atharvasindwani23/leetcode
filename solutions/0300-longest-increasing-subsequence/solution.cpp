#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> memo;

    int helper(int i, int prevIdx) {
        if (i == n) return 0;

        int &res = memo[i][prevIdx + 1]; // shift prevIdx by +1 to allow -1
        if (res != -1) return res;

        // Option 1: skip nums[i]
        res = helper(i + 1, prevIdx);

        // Option 2: take nums[i] if increasing
        if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
            res = max(res, 1 + helper(i + 1, i));
        }
        return res;
    }

    int lengthOfLIS(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        memo.assign(n, vector<int>(n + 1, -1));
        return helper(0, -1);
    }
};

