class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int i  = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        priority_queue<int> pq;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            for (int i  = 0 ; i < x->second; i++) {
                pq.push(x->first);
            }
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
