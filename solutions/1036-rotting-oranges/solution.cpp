class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> bfs;
    int freshCount = 0, minutes = 0;

    // Step 1: Store all initially rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                bfs.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges, return 0 immediately
    if (freshCount == 0) return 0;

    // Possible directions: Down, Up, Right, Left
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Step 2: BFS
    while (!bfs.empty()) {
        int size = bfs.size();
        bool rotted = false;

        for (int i = 0; i < size; i++) {
            auto [x, y] = bfs.front();
            bfs.pop();

            for (auto& d : directions) {
                int newX = x + d.first, newY = y + d.second;

                // Check if within bounds and is a fresh orange
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;  // Rot the orange
                    bfs.push({newX, newY});
                    freshCount--;
                    rotted = true;
                }
            }
        }

        // If at least one orange was rotted this minute, increase time
        if (rotted) minutes++;
    }

    // Step 3: Check if all fresh oranges rotted
    return freshCount == 0 ? minutes : -1;
}
    // [i][j] => 2
    // [i + 1][j] == 1 -> 2
    // [i - 1][j] == 1 -> 2
    //..
    // ..
};
