class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j)) count++;
            }
        }

        return count;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Step 1: check if values are 1-9 and distinct
        vector<int> freq(10, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || freq[val] == 1) return false;
                freq[val] = 1;
            }
        }

        // Step 2: calculate sums of rows, cols, diags
        int target = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        // check rows
        for (int i = r; i < r + 3; i++) {
            int sum = 0;
            for (int j = c; j < c + 3; j++) sum += grid[i][j];
            if (sum != target) return false;
        }

        // check columns
        for (int j = c; j < c + 3; j++) {
            int sum = 0;
            for (int i = r; i < r + 3; i++) sum += grid[i][j];
            if (sum != target) return false;
        }

        // check diagonals
        int diag1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int diag2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        return diag1 == target && diag2 == target;
    }
};

