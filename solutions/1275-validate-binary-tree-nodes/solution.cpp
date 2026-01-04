class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>treeGraph(n);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
            treeGraph[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
            treeGraph[i].push_back(rightChild[i]);
            }
        }

        unordered_map<int,int> indegree;

        for (int i = 0; i < n; i++) {
            int parent = i;
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                indegree[left]++;
                if (indegree[left] > 1) {
                    return false;
                }
            }
            if (right != -1) {
                indegree[right]++;
                if (indegree[right] > 1) {
                    return false;
                }
            }
        }
        int count = 0;
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                root = i;
                count++;
            }
        }
        if (count != 1) {
            return false;
        }
        //topoSort to detect cycles
        queue<int> elements;
        elements.push(root);
        int size = 0;
        while (!elements.empty()) {
            int curr = elements.front();
            elements.pop();
            size++;
            for (int nei : treeGraph[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    elements.push(nei);
                }
            }
        }
        return size == n;    }
        //

   
   
    //to find the children of a node i
    //leftChild[i], rightChild[i]
    //there is one connected component
    //there should be no cyclces
    //there should be one parent for each node

    //child[child[i]] == i => cycle

};
