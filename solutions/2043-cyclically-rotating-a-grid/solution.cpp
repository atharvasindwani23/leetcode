class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int left = 0, right = grid[0].size() - 1;
        int up = 0, down = grid.size() - 1;

        while (left < right && up < down) {
            // Collect full ring in clockwise order
            vector<pair<int,int>> positions;
            
            for (int i = left; i <= right; i++)  positions.push_back({up, i});
            for (int i = up+1; i <= down; i++)   positions.push_back({i, right});
            for (int i = right-1; i >= left; i--) positions.push_back({down, i});
            for (int i = down-1; i > up; i--)    positions.push_back({i, left});

            vector<int> vals;
            for (auto [i, j] : positions)
                vals.push_back(grid[i][j]);

            // Shift by k % ring size instead of 1 step at a time
            int shift = k % vals.size();
            rotate(vals.begin(), vals.begin() + shift, vals.end());

            for (int idx = 0; idx < positions.size(); idx++) {
                auto [i, j] = positions[idx];
                grid[i][j] = vals[idx];
            }

            left++; right--;
            up++; down--;
        }

        return grid;
    }
};
