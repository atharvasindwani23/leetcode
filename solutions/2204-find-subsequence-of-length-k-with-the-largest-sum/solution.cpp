class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
    }
    vector<int> returner;
    for (int i = 0; i < k; i++) {
        auto x = pq.top();
        returner.push_back(x.second);
        pq.pop();
    
    }
    vector<int> res;
    sort(returner.begin(), returner.end());
    for (int idx : returner) {
        std::cout << idx << std::endl;
        res.push_back(nums[idx]);
    }
    return res;
    }

    //additional constraint here is the length k part of the question, we need to enforce it to pick up k elements
    //heres why its a bit tricky to me, we will need to have a 2d array now dp(i,n) where n would represent how many elements we have yet to pick up  
    //at every point you have two options, either leave it or pick it up if you remember

    // [i .. n] dp[0] return, dp[nums.size() - 1], either pick it up or leave it, depends on if the number is + or 0
    //dp[i] = max(dp[i + 1], nums[i] + dp[i + 1])

    //good q will recap subsequences for you, do this then internship work :(
};
