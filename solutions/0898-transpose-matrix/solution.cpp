class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    vector<vector<int>> returner(matrix.at(0).size(), vector<int>(matrix.size()));
    for (unsigned int i = 0; i < matrix.at(0).size(); i++) {
        for (unsigned int j = 0; j < matrix.size(); j++) {
          returner[i][j] = matrix[j][i];
        }
    }
    return returner;
    }
};
