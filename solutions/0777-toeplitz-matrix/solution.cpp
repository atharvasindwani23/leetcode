class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        return columnHelper(matrix);
    }
    bool columnHelper(vector<vector<int>>& matrix) {
        for (unsigned int i =  0; i < matrix.size() - 1; i++) {
            for (unsigned int j = 0; j < matrix.at(i).size() - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                     return false;
                  }
            }
    }
    return true;
}
};
