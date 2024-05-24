class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::vector<bool> returner(candies.size(), false);
        for (unsigned int i = 0; i < candies.size(); i++) {
            if (helper(candies, candies[i] + extraCandies)) {
               returner[i] = true;
            } else {
                returner[i] = false;
            }
        }
        return returner;
    }
    bool helper(vector<int>& candies, int a) {
       int max = 0;
       for (int i : candies) {
        if (i > max) {
            max = i;
        }
       }
       return (a >= max);
    }
};
