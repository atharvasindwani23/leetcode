class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     vector<vector<int>> t = matrix;
     for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix.size(); j++) {
            matrix[j][matrix.size() - i - 1] = t[i][j];
        }
     }
    }
};
