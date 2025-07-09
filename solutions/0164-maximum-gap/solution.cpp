class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mina = *min_element(nums.begin(), nums.end());
        int maxa = *max_element(nums.begin(), nums.end());
        if (mina == maxa) return 0;  // All elements same

        int bucketSize = max(1, (maxa - mina) / (n - 1));
        int bucketCount = (maxa - mina) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int num : nums) {
            int idx = (num - mina) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        int maxGap = 0;
        int prevMax = mina;

        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};

