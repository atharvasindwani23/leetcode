class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        dp[cost.size() - 1] = cost[cost.size() - 1];
        for (int i = cost.size() - 2; i >= 0; i--) {
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
        }
        return min(dp[0], dp[1]);
    }

    //i -> n approach might be better in this case
    //what that means is that we return min(dp[0], dp[1])


    //okay this is a classic dp problem lets think about it simply
    //we have an array, where we know that we need to figure out the min cost to climb the stairs
    // we are posed with possibilities of either climbing one step at a time or two
    // ie our total cost of reaching step[i] = cost[i] + min(step[i - 2], step[i - 1]);
    //we want to return step[n] where n is the top most floor.
    //a classic 
};
