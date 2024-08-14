class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> returner;
    int top = 0;
    int row = matrix.size();
    int col = matrix.at(0).size();
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;
    int direction = 1;
    while (left <= right && bottom >= top) {
          if (direction == 1) {
            for (unsigned int i = left; i <= right; i++) {
                returner.push_back(matrix[top][i]);
            }
            direction = 2;
            top++;
          }
          if (direction == 2) {
            for (unsigned int i = top; i <= bottom; i++) {
                returner.push_back(matrix[i][right]);
                
                direction = 3;
            }
            right--;
          }
          if (direction == 3) {
            for (int i = right; i >= left; i--) {
                returner.push_back(matrix[bottom][i]);
                direction = 4;;
            }
            bottom--;

          }
            if (direction == 4) {
                for (int i = bottom; i >= top; i--) {
                    returner.push_back(matrix[i][left]);
                }
                left++;
                direction = 1;
            }
          }
          return returner;
    }
};
