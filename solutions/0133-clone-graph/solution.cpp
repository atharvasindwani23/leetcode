/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        std::map<Node*, Node*> copies;
        Node* start = new Node(node->val);
        copies[node] = start;
        queue<Node*>bfs;
        bfs.push(node);
        while (!bfs.empty()) {
         Node* temp = bfs.front();
         for (Node* neighbor : temp->neighbors) {
               if (!copies.contains(neighbor)) {
                copies[neighbor] = new Node(neighbor->val);
                bfs.push(neighbor);
               }
               copies[neighbor]->neighbors.push_back(copies[temp]); 
         }
         bfs.pop();
        }
        return start;
    }
};
