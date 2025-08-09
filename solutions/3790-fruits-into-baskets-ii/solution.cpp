class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        map<int, bool> present;
        int placed = 0;
        for (int i  = 0; i < fruits.size(); i++) {
            for (int j  = 0; j < baskets.size(); j++) {
                if (baskets[j] >= fruits[i] && !present[j]) {
                    placed++;
                    present[j] = true;
                    break;
                }
            }
            }
            return fruits.size() - placed;
        }   
    //sweep from left to right
};
