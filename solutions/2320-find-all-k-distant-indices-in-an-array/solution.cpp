class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> returner;
        int n = nums.size();
        int last_added = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int start = max(i - k, last_added + 1);  // Avoid duplicates
                int end = min(i + k, n - 1);
                for (int j = start; j <= end; ++j) {
                    returner.push_back(j);
                }
                last_added = end;  // Move up last added pointer
            }
        }

        return returner;
    }
};

