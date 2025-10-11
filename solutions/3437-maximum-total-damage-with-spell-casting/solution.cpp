class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> sum;
        for (int p : power) sum[p] += p;  // group duplicates

        vector<int> keys;
        for (auto& [k, _] : sum) keys.push_back(k);
        sort(keys.begin(), keys.end());

        int n = keys.size();
        vector<long long> dp(n, 0);
        dp[0] = sum[keys[0]];

        for (int i = 1; i < n; i++) {
            long long take = sum[keys[i]];
            int j = i - 1;

            // find last compatible (keys[j] < keys[i] - 2)
            while (j >= 0 && keys[i] - keys[j] <= 2) j--;
            if (j >= 0) take += dp[j];

            long long skip = dp[i - 1];
            dp[i] = max(take, skip);
        }

        return dp[n - 1];
    }
};

