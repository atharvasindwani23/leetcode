class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxi = 0;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            maxi = max(x->second, maxi);
        }
        int count = 0;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            if (x->second == maxi) {
                count++;
            }
        }
        return count * maxi;
    }
};
