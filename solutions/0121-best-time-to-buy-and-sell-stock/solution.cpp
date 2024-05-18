class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // If the list is empty or has only one price, no profit can be made
        if (prices.size() < 2) return 0;

        // Initialize the minimum price to the first element and max profit to 0
        int min_price = prices[0];
        int max_profit = 0;

        // Iterate through the list starting from the second element
        for (size_t i = 1; i < prices.size(); ++i) {
            // Calculate the potential profit at the current price
            int potential_profit = prices[i] - min_price;
            // Update the max profit if the current potential profit is higher
            max_profit = std::max(max_profit, potential_profit);
            // Update the minimum price to the current price if it's lower
            min_price = std::min(min_price, prices[i]);
        }

        // Return the maximum profit found
        return max_profit;
    }
};
