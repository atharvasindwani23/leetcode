class Solution {
public:
    int solve(vector<int>& firstStart, vector<int>& firstDuration,
              vector<int>& secondStart, vector<int>& secondDuration) {
        
        int n = firstStart.size();
        int m = secondStart.size();

        vector<pair<int, int>> second;

        for (int i = 0; i < m; i++) {
            second.push_back({secondStart[i], secondDuration[i]});
        }

        sort(second.begin(), second.end());

        vector<int> prefixMinDuration(m);
        vector<int> suffixMinFinish(m);

        prefixMinDuration[0] = second[0].second;

        for (int i = 1; i < m; i++) {
            prefixMinDuration[i] = min(prefixMinDuration[i - 1], second[i].second);
        }

        suffixMinFinish[m - 1] = second[m - 1].first + second[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] = min(
                suffixMinFinish[i + 1],
                second[i].first + second[i].second
            );
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int firstFinish = firstStart[i] + firstDuration[i];

            int idx = upper_bound(
                second.begin(),
                second.end(),
                make_pair(firstFinish, INT_MAX)
            ) - second.begin();

            // second rides with start <= firstFinish
            // choose minimum duration among them
            if (idx > 0) {
                ans = min(ans, firstFinish + prefixMinDuration[idx - 1]);
            }

            // second rides with start > firstFinish
            // choose minimum start + duration among them
            if (idx < m) {
                ans = min(ans, suffixMinFinish[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int landThenWater = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        int waterThenLand = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return min(landThenWater, waterThenLand);
    }
};
