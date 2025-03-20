class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        // Base cases
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if (image[sr][sc] != originalColor || image[sr][sc] == color) return;

        // Color the current pixel
        image[sr][sc] = color;

        // Explore adjacent cells
        dfs(image, sr + 1, sc, color, originalColor);
        dfs(image, sr - 1, sc, color, originalColor);
        dfs(image, sr, sc + 1, color, originalColor);
        dfs(image, sr, sc - 1, color, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};

