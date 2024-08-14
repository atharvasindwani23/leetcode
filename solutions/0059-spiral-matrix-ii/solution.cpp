class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> returner(n, vector<int>(n, 0));
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int direction = 1;
    int number = 1;
    while (left <= right && top <= bottom) {
    if (direction == 1) {
     for (unsigned int i = left; i <= right ; i++) {
        returner[top][i] = number;
        number++;
     }
     top++;
     direction = 2;
    }
     if (direction == 2) {
        for (unsigned int i = top; i <= bottom; i++) {
            returner[i][right] = number;
            number++;
        }
        right--;
        direction = 3;
     }
     if (direction == 3) {
        for (int i = right; i >= left; i--) {
            returner[bottom][i] = number;
            number++;
        }
        bottom--;
        direction = 4;
     }
     if (direction == 4) {
        for (int i = bottom; i >= top; i--) {
            returner[i][left] = number;
            number++;
        }
        left++;
        direction = 1;
     }
    }
    return returner;
    }
};
