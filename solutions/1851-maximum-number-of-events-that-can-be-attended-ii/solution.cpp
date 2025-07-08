class Solution {
public:
   int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());  // Sort by start day
    int n = events.size();
    
    // Sort events by end time
    sort(events.begin(), events.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    // Extract start times for binary search
    vector<int> endTimes;
    for (auto& e : events) {
        endTimes.push_back(e[1]);
    }

    // dp[i][j] = max value using first i events and selecting j events
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int start = events[i-1][0];
        int end = events[i-1][1];
        int val = events[i-1][2];

        // Find the last event that ends before this event's start
        int prev = upper_bound(endTimes.begin(), endTimes.begin() + i - 1, start - 1) - endTimes.begin();

        for (int j = 1; j <= k; ++j) {
            // Either skip or attend
            dp[i][j] = max(dp[i-1][j], dp[prev][j-1] + val);
        }
    }

    return dp[n][k];
}

};
