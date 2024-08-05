class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int returner = 0;
    int left = 0;
    int right = 1;
    while (right < prices.size()) {
        if (prices[left] >= prices[right]) {
            left = right;
            right++;
        } else {
            returner = std::max(returner, prices[right] - prices[left]);
            right++;
        }
    }
    return returner;
    }
};
