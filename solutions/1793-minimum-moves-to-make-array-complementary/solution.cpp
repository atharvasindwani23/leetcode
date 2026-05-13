class Solution {
public:

int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();
    int half = n / 2;
    
    vector<int> small, large;
    unordered_map<int, int> sum_count;
    
    for (int i = 0; i < half; i++) {
        int a = min(nums[i], nums[n-1-i]);
        int b = max(nums[i], nums[n-1-i]);
        small.push_back(a);
        large.push_back(b);
        sum_count[a + b]++;
    }
    
    sort(small.begin(), small.end());
    sort(large.begin(), large.end());
    
    int ans = INT_MAX;
    
    for (int c = 2; c <= 2 * limit; c++) {
        int already = sum_count.count(c) ? sum_count[c] : 0;
        
        // pairs where a > c-1, i.e., a >= c → need 2 ops
        int need_two_small = half - (int)(lower_bound(small.begin(), small.end(), c) - small.begin());
        
        // pairs where b < c - limit → need 2 ops
        int need_two_large = (int)(lower_bound(large.begin(), large.end(), c - limit) - large.begin());
        
        int ops = half - already + need_two_small + need_two_large;
        ans = min(ans, ops);
    }
    
    return ans;
}
    //complementary array means that if we have nums and we have nums_1 = reverse(nums) then nums[i] + nums_1[i] will be the same number
};
