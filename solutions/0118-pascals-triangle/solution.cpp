class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //vector at index i will have a size of i + 1 such that 
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows == 1) {
            return res;
        }
        res.push_back({1,1});
        if (numRows == 2) {
            return res;
        }
        for (int i = 2; i < numRows; i++) {
            vector<int>flag(i + 1, 1);
            //[1,1]
            //[1,1]
            //[1,1,1]
            for (int j = 1; j < i ; j++) {
                flag[j] = res[i - 1][j] + res[i - 1][j - 1];
                // [1, ]
            }
            res.push_back(flag);
        }
        return res;

         //res[i][j] = res[i - 1][j] + res[i-1][j - 1];
    }
};
