class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int l = 0;
     int r = 1;
     int maxProf = 0;
     while (r < prices.size()) {

        if (prices[l] < prices[r]) {
            maxProf = max(maxProf, prices[r] - prices[l]);
        } else {
            l = r;
        }
        r++;
     }
     return maxProf;   
    }


    //maximium difference between prices[i] - prices[j] such that j > i => naive solution is o(n^2)
    //two pointer method which we can use
    //start off adjacent, tabulate the difference, store it in max, keep l fixed and move r 
    // if l > r => l = r, r = r + 1
};
