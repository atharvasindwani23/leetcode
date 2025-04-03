class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1); // dp[i] stores the length of the increasing subsequence ending at index i
        vector<int> dp2(n, 1); // dp2[i] stores the length of the decreasing subsequence starting at index i
        int ans = 0; // Variable to store the maximum length of a mountain sequence

        // Calculate the length of the increasing subsequence ending at each index
        for (int ind = 1; ind < n; ind++) {
            if (arr[ind] > arr[ind - 1]) {
                // If the element at the current index is greater than the previous element,
                // we can extend the increasing subsequence. Increment dp[ind] by 1.
                dp[ind] = 1 + dp[ind - 1];
            }
        }

        // Calculate the length of the decreasing subsequence starting at each index
        for (int ind = n - 2; ind >= 0; ind--) {
            if (arr[ind] > arr[ind + 1]) {
                // If the element at the current index is greater than the next element,
                // we can extend the decreasing subsequence. Increment dp2[ind] by 1.
                dp2[ind] = 1 + dp2[ind + 1];
            }
        }

        // Iterate over each index and find the maximum length of a mountain sequence
        for (int i = 0; i < n; i++) {
            if (dp[i] > 1 && dp2[i] > 1) {
                // If both the increasing and decreasing subsequences have lengths greater than 1 at index i,
                // calculate the length of the mountain sequence by summing the lengths of the subsequences
                // and subtracting 1 (to avoid counting the same element twice). Update the ans variable.
                ans = max(dp[i] + dp2[i] - 1, ans);
            }
        }

        return ans; // Return the maximum length of a mountain sequence
    }
};
