class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       vector<int>prices(n, INT_MAX);
       prices[src] = 0;
       for (int stop = 0; stop <= K; stop++) {
        vector<int>copy(prices);
        for (auto flight : flights) {
           int from_cost = flight[0];
           int to_cost = flight[1];
           int price = flight[2];
           if (prices[from_cost] != INT_MAX) {
            copy[to_cost] = min(prices[from_cost] + price, copy[to_cost]);
           }
        }
        prices = copy;
       }
       if (prices[dst] == INT_MAX) {
        return -1;
       }
       return prices[dst];
    }
};

