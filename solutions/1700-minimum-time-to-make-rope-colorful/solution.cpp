class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
    int total = 0;
    for (int i = 1; i < colors.size(); i++) {
        if (colors[i] == colors[i - 1]) {
            total += min(neededTime[i], neededTime[i - 1]);
            neededTime[i] = max(neededTime[i], neededTime[i - 1]); // keep the higher one
        }
    }
    return total;
}




    
    //choices -> if we have two consecetive balloons, we need to for sure pop/burst/remove one of them
    //we remove the one which has a lesser value  => is this dp, is the question im asking myself
    //dp[i] minimum possible cost -> uptill i or from i -> n
    //so if im on balloon "i" -> if different from i + 1 -> dont burst -> dp[i] = dp[i + 1] + nums[i]
    //else burst i or burst i  + 1 -> so dp[i] = min(dp[i + 1] - neededTime[i], dp[i + 1])





};
