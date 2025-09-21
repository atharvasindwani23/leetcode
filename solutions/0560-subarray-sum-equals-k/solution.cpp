#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;                     
        int ans = 0;
        unordered_map<int,int> cnt;     
        cnt[0] = 1;                     

        for (int x : nums) {
            sum += x;
            if (cnt.find(sum - k) != cnt.end()) {
                ans += cnt[sum - k];    
            }
            cnt[sum]++;                
        }
        return ans;
    }
};

