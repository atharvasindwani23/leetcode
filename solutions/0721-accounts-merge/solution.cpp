#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;  // email -> neighbors
        unordered_map<string, string> emailToName;    // email -> name

        // Build graph: connect each email in an account to the first email
        for (const vector<string>& acc : accounts) {
            const string& name = acc[0];
            if (acc.size() < 2) continue; // no email, just in case
            const string& firstEmail = acc[1];

            // Ensure firstEmail exists as a node
            if (!graph.count(firstEmail)) graph[firstEmail] = {};

            for (int i = 1; i < (int)acc.size(); i++) {
                const string& email = acc[i];
                emailToName[email] = name;

                if (email != firstEmail) {
                    graph[firstEmail].push_back(email);
                    graph[email].push_back(firstEmail);
                } else {
                    // also ensure node exists
                    if (!graph.count(email)) graph[email] = {};
                }
            }
        }

        // DFS over email graph to collect connected components
        unordered_set<string> visited;
        vector<vector<string>> result;

        for (const auto& p : graph) {
            const string& start = p.first;
            if (visited.count(start)) continue;

            vector<string> stack;
            vector<string> component;
            stack.push_back(start);
            visited.insert(start);

            while (!stack.empty()) {
                string u = stack.back();
                stack.pop_back();
                component.push_back(u);

                for (const string& v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        stack.push_back(v);
                    }
                }
            }

            sort(component.begin(), component.end());
            vector<string> merged;
            merged.push_back(emailToName[component[0]]);
            for (const string& e : component) merged.push_back(e);
            result.push_back(merged);
        }

        return result;
    }
};

