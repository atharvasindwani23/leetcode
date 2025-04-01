class Solution {
public:
    void bfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &comp) {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            comp.push_back(curr);
            for (int neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                bfs(i, adj, vis, comp);
                
                bool isComplete = true;
                for (int node : comp) {
                    if (adj[node].size() != comp.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) completeCount++;
            }
        }

        return completeCount;
    }
};

