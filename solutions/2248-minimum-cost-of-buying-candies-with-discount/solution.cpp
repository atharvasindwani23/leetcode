class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());

        int totalCost = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }
        return totalCost;
    }

    //paying for most two expensive ones, skipping the third one. can sort it and do the modulo operation. ez
};
