class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
        }
        for (int i = 0; i < nums.size() - k; i++) {
            pq.pop();
        }
        return pq.top();
    }


    // [1 2 3 4 5 6] -> 2nd largest = 5th smallest, nth largest = (size - n + 1)th smallest
    //pop size - n times then?
};
