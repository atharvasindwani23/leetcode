class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k == 1) return n; // every single element works

        // make circular by appending
        for (int i = 0; i < n; i++) colors.push_back(colors[i]);

        // build prefix of alternating adjacencies
        vector<int> alt(colors.size(), 0);
        for (int i = 1; i < colors.size(); i++) {
            alt[i] = (colors[i] != colors[i - 1]) ? 1 : 0;
        }

        // sliding window sum over alt[]
        int count = 0;
        int windowSum = 0;
        for (int i = 1; i < k; i++) windowSum += alt[i]; // first window

        if (windowSum == k - 1) count++;

        for (int i = k; i < n + k - 1; i++) {
            windowSum += alt[i] - alt[i - (k - 1)];
            if (windowSum == k - 1) count++;
        }

        return count;
    }
};

