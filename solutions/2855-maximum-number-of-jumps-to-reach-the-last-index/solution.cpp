class Solution {
//dp[i] is the maximum number of jumps to reach index i from 0
//to return dp[nums.size() - 1];
//reccurence -> dp[j] = max(1 + dp[i]) where abs(nums[j] - nums[i]) <= target
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }
        if (dp[nums.size() - 1] < 0) {
            return -1;
        }
        return dp[nums.size() - 1];
    }

    //ypu greedily go to the first index which satisfies your thing.
    //goal is to get to the last index which would be nums.size() - 1;

    //q is will this greedy approach always work?
    //will have to test -> what if we have a case if we go w this greedy approach but can't reach the last element but there might be a non greedy way to reach the last element
};


//if not greedy then probably dp

