class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1)); // store distances
        queue<pair<int, int>> q;

        // Step 1: Enqueue all 0s and set their distance to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Standard BFS from all 0s
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int ni = i + dx;
                int nj = j + dy;

                // Valid and not visited
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && res[ni][nj] == -1) {
                    res[ni][nj] = res[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return res;
    }
};

