class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> results;

        queue<pair<int,int>> pacificSources;
        queue<pair<int,int>> atlanticSources;
        map<pair<int,int>, bool> visitedPacific;
        map<pair<int,int>, bool> visitedAtlantic;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    pacificSources.push({i, j});
                    visitedPacific[{i, j}] = true;
                }
                if (i == n - 1 || j == m - 1) {
                    atlanticSources.push({i, j});
                    visitedAtlantic[{i, j}] = true;
                }
            }
        }
        bfs(visitedPacific, pacificSources, heights);
        bfs(visitedAtlantic, atlanticSources, heights);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visitedPacific[{i, j}] && visitedAtlantic[{i, j}]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }


    void bfs(map<pair<int,int>, bool>& visited, queue<pair<int,int>> sources, vector<vector<int>>& heights) {

        while (!sources.empty()) {
            int row = sources.front().first;
            int col = sources.front().second;
            sources.pop();
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < 4; i++) {
                int curr_row = directions[i][0] + row;
                int curr_col = directions[i][1] + col;
                if (curr_row < 0 || curr_col < 0 || curr_row >= heights.size() || curr_col >= heights[0].size()) {
                    continue;
                }
                if (visited[{curr_row, curr_col}]) {
                    continue;
                }
                if (heights[row][col] <= heights[curr_row][curr_col]) {
                    visited[{curr_row, curr_col}] = true;
                    sources.push({curr_row, curr_col});
                }
            }
        }
    }



    // sources for pacific ocean => [row 0, col 0]
    // sources for atlantic ocean => [row = n - 1, col = m - 1]
};
