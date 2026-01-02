class Solution {
public:
    // Get the ID of the bucket from element value x and bucket width w
    // This function handles floor division correctly for both positive and
    // negative numbers.
    long getID(long x, long w) { return x < 0 ? (x + 1) / w - 1 : x / w; }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<long, long> buckets;
        long w = (long)t + 1;
        for (int i = 0; i < nums.size(); ++i) {
            long bucket = getID(nums[i], w);
            // Check if current bucket is empty, each bucket may contain at most
            // one element
            if (buckets.count(bucket)) return true;
            // Check the neighbor buckets for almost duplicate
            if (buckets.count(bucket - 1) &&
                abs(nums[i] - buckets[bucket - 1]) < w)
                return true;
            if (buckets.count(bucket + 1) &&
                abs(nums[i] - buckets[bucket + 1]) < w)
                return true;
            // Now bucket is empty and no almost duplicate in neighbor buckets
            buckets[bucket] = (long)nums[i];
            if (i >= k) {
                buckets.erase(getID(nums[i - k], w));
            }
        }
        return false;
    }
};
