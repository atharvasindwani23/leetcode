class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int left = 0, right = cells.size(), ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // build grid for "mid" days
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < mid; i++) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                grid[r][c] = 1; // water
            }

            // if we can cross on this day, search right (try later day)
            if (canCross(row, col, grid)) {
                ans = mid;
                left = mid + 1;
            } 
            // otherwise search earlier day
            else {
                right = mid - 1;
            }
        }

        return ans;
    }


    bool canCross(int row, int col, vector<vector<int>>& grid) {

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        queue<pair<int,int>> q;

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == row - 1) return true;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                if (vis[nx][ny] || grid[nx][ny] == 1) continue;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }
};

