class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // mark guards as 1
        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        // mark walls as -1
        for (auto& w : walls) {
            grid[w[0]][w[1]] = -1;
        }
        
        // directions: up, down, left, right
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        // for each guard, mark visible cells
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            
            for (auto& d : dirs) {
                int i = x + d[0], j = y + d[1];
                
                while (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] != -1 && grid[i][j] != 1) {
                    // mark as guarded
                    if (grid[i][j] == 0) grid[i][j] = 2;
                    i += d[0];
                    j += d[1];
                }
            }
        }
        
        int unguarded = 0;
        // count unguarded cells (0)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) unguarded++;
            }
        }
        
        return unguarded;
    }
};

