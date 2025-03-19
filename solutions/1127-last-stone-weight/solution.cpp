class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::sort(stones.begin(), stones.end()); 
        if (stones.size() == 1) {
            return stones.at(0);
        }
        if (stones.size() == 0) {
            return 0;
        }
        int x = stones[stones.size() - 2];
        int y = stones[stones.size() - 1];
        if (x == y) {
            stones.erase(stones.begin() + stones.size() - 2);
            stones.erase(stones.begin() + stones.size() - 1);
        } else {
           stones.erase(stones.begin() + stones.size() - 2);
           stones[stones.size() - 1] = y - x;
         }
         return lastStoneWeight(stones);
    }
};
