class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>  copier = copy(matrix);
        for (unsigned int i = 0; i < matrix.size(); i++) {
            for (unsigned int j = 0; j < matrix.size(); j++) {
              matrix.at(i).at(j) = copier.at(matrix.size() - j - 1).at(i);
        }
    }
}
 vector<vector<int>> copy(const vector<vector<int>>& matrix) {
    vector<vector<int>> returner(matrix.size(), vector<int>(matrix.size()));
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix.size(); j++) {
            returner[i][j] = matrix[i][j];
        }
    }
    return returner;
}
};
