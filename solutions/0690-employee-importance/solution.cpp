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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> idEmp_;

        for (Employee* emp : employees) {
            idEmp_[emp->id] = emp;
        }
        Employee* specialEmp_ = idEmp_[id];

        queue<Employee*> empTree;

        set<Employee*> visited;

        empTree.push(specialEmp_);

        visited.insert(specialEmp_);

        int sum = 0;
        

        while (!empTree.empty()) {

            Employee* first = empTree.front();
            empTree.pop();

            sum += first->importance;

            for (int id : first->subordinates) {
                Employee* e = idEmp_[id];
                if (!visited.count(e)) {
                    visited.insert(e);
                    empTree.push(e);
                }
            }
        }

        return sum;

        //run bfs on this PARTICULAR EMPLOYEE
    }

    //calculate the sum of all the nodes in a tree
    //how do we go about this
    // we know that every employee has a unique id
    //goal is to find that id and then do a very simple bfs on the particular id to calculate the sum
    //we can unwrap the employees vector and create a hashmap which gives us O(1) access to the employee object
};
