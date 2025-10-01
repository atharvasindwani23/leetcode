class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int res = empty;
        while (empty >= numExchange) {
            res += empty / numExchange;
            empty = empty % numExchange + empty / numExchange;
        }
            return res;
        }
};



// 15 empty bottles - 4 - 4
