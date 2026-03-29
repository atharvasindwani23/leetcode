/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> children;
    unordered_map<int, Employee*> id_emp;
    int getImportance(vector<Employee*> employees, int id) {
        Employee* special;
        for (Employee* employee : employees) {
            if (employee->id == id) {
                special = employee;
            }
            id_emp[employee->id] = employee;
            children[employee->id] = employee->subordinates; //o(n) operation
        }
        queue<Employee*> bfs;
        unordered_set<Employee*> visited;
        bfs.push(special);
        int sum = 0;
        while (!bfs.empty()) {
            auto x = bfs.front();
            bfs.pop();
            sum += x->importance;

            for (int emp : children[x->id]) {
                if (!visited.count(id_emp[emp])) {
                    visited.insert(id_emp[emp]);
                    bfs.push(id_emp[emp]);
                }
            }
        }
        return sum;
    }

    //easy => pretty much the sum of the tree
    //once we get this special id we essentially just want to do a bfs/dfs to calculate the sum of everything else
    //now if we had a map of sorts this would get easier => how? we'll have an id mapped to its importance and a vector of its direct children => unordered_map<int, vector<int>>




};
