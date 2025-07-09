class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;
    unordered_set<string> supplySet(supplies.begin(), supplies.end());
    queue<string> q;

    // Build the graph and indegree
    for (int i = 0; i < recipes.size(); i++) {
        for (string& ing : ingredients[i]) {
            graph[ing].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }

    // Initialize queue with supplies
    for (string& s : supplies) {
        q.push(s);
    }

    vector<string> result;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        for (string& next : graph[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                result.push_back(next);
                q.push(next);
            }
        }
    }

    return result;
}

};
