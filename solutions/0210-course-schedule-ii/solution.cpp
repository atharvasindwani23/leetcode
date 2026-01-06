class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;

        unordered_map<int,vector<int>> neighbours;

        for (vector<int> prereq : prerequisites) {
            neighbours[prereq[1]].push_back(prereq[0]);
        }
        cout << neighbours.size();
        unordered_map<int,int> indegree;

        for (auto x = neighbours.begin(); x != neighbours.end(); x++) {
            for (int neigh : x->second) {
                indegree[neigh]++;
            }
        }
        
        queue<int> sources;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                sources.push(i);
            }
        }
        cout << sources.size();
        int count = 0;
        while (!sources.empty()) {
            int curr = sources.front();
            result.push_back(curr);
            count++;
            sources.pop();
            for (int nei : neighbours[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    sources.push(nei);
                }
            }
        }
        if (count == numCourses) {
            return result;
        }
        return {};
    }
};
