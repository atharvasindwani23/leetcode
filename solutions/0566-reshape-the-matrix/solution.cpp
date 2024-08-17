class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
     if (r * c  != mat.size() * mat.at(0).size()) {
        return mat;
     }
     vector<vector<int>> returner;
     vector<int> flag;
     for (unsigned int i = 0; i < mat.size(); i++) {
        for (unsigned int j = 0; j < mat.at(0).size(); j++) {
          flag.push_back(mat[i][j]);
          if (flag.size() == c) {
            returner.push_back(flag);
            flag.clear();
          }
        }
     }
     return returner;
    }
};
