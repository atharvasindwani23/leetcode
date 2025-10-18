#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1e9 + 7;

        // max-heap for buy orders (highest price first)
        priority_queue<pair<int,int>> buyHeap;
        // min-heap for sell orders (lowest price first)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sellHeap;

        for (auto &order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];

            if (type == 0) { 
                // BUY order
                // Try to match with lowest sell prices
                while (amount > 0 && !sellHeap.empty() && sellHeap.top().first <= price) {
                    auto [sellPrice, sellAmount] = sellHeap.top();
                    sellHeap.pop();

                    int matched = min(amount, sellAmount);
                    amount -= matched;
                    sellAmount -= matched;

                    // If the sell order still has remaining amount, push it back
                    if (sellAmount > 0) {
                        sellHeap.push({sellPrice, sellAmount});
                        break;
                    }
                }

                // If still unfulfilled, add remaining to buy backlog
                if (amount > 0) {
                    buyHeap.push({price, amount});
                }
            } 
            else { 
                // SELL order
                // Try to match with highest buy prices
                while (amount > 0 && !buyHeap.empty() && buyHeap.top().first >= price) {
                    auto [buyPrice, buyAmount] = buyHeap.top();
                    buyHeap.pop();

                    int matched = min(amount, buyAmount);
                    amount -= matched;
                    buyAmount -= matched;

                    // If the buy order still has remaining amount, push it back
                    if (buyAmount > 0) {
                        buyHeap.push({buyPrice, buyAmount});
                        break;
                    }
                }

                // If still unfulfilled, add remaining to sell backlog
                if (amount > 0) {
                    sellHeap.push({price, amount});
                }
            }
        }

        // Compute remaining total orders in backlog
        long long total = 0;
        while (!buyHeap.empty()) {
            total = (total + buyHeap.top().second) % MOD;
            buyHeap.pop();
        }
        while (!sellHeap.empty()) {
            total = (total + sellHeap.top().second) % MOD;
            sellHeap.pop();
        }

        return total;
    }
};

