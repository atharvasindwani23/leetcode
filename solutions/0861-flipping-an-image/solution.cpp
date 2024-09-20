class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        unsigned int rows = image.size();
        unsigned int cols = image.at(0).size();
        for (unsigned int i = 0; i < cols / 2; i++) {
            for (unsigned int j = 0; j < rows; j++) {
               // [j][i] => [j][cols - 1 - i]
               int temp = image[j][i];
               image[j][i] = image[j][cols - 1 - i];
               image[j][cols - 1 - i] = temp;
            }
        }
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                if(image[i][j] == 0) {
                    image[i][j] = 1;
                } else {
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
    // 0 1 1 
    //1 0 1
    //0  0 0
};

