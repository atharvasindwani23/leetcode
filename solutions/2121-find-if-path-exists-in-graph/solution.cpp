class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      map<int, vector<int>> neighbours;
      for (int i = 0; i < edges.size(); i++) {
        neighbours[edges[i][0]].push_back(edges[i][1]);
        neighbours[edges[i][1]].push_back(edges[i][0]);
      }
        return bfs(neighbours, source, destination);
    }

    bool bfs(map<int,vector<int>> neighbours, int source, int destination) {
        queue<int> q;
        q.push(source);
        map<int,bool> visited;
        visited[source] = true;
        while (q.size() != 0) {
            int top = q.front();
            if (top == destination) {
                return true;
            }
            q.pop();
            for (int curr : neighbours[top]) {
                if (!visited[curr]) {
                    q.push(curr);
                    visited[curr] = true;
                } else {
                    if (curr == destination) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};
