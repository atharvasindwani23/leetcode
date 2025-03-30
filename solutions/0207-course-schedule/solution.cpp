class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list to represent the course dependency graph
        vector<vector<int>> adj(numCourses);
        // In-degree array to track the number of prerequisites for each course
        vector<int> inDegree(numCourses, 0);
        
        // Build the adjacency list and in-degree count
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // pre[1] -> pre[0] (course pre[1] must be taken before pre[0])
            inDegree[pre[0]]++; // Increase in-degree for the dependent course
        }
        
        queue<int> q;
        // Add all courses that have no prerequisites (in-degree 0) to the queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // Counter for the number of courses that can be taken
        
        while (!q.empty()) {
            int course = q.front(); q.pop(); // Process the next available course
            count++; // Successfully taken this course
            
            // Reduce the in-degree of dependent courses
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                // If a course has no more prerequisites, add it to the queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we have been able to take all courses, there is no cycle
        return count == numCourses;
    }
};

