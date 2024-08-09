class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat.at(0).size()) {
            return mat;
        }
       int count_i = 0;
       int count_j = 0;
vector<vector<int>> returner(r, vector<int>(c));
        for (unsigned int i = 0; i < r; i++) {
            for (unsigned int j = 0; j < c ; j++) {
                returner[i][j] = mat.at(count_i).at(count_j);
                count_j++;
                if (count_j >= mat.at(0).size()) {
                    count_i++;
                    count_j = 0;
                }
            }
        }
        return returner;
    }
};
