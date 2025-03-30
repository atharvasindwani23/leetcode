class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> returner;
       if (!root) {
        return returner;
       }
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int sizeQ = bfs.size();
            vector<int>flag;
            for (int i  = 0; i < sizeQ; i++) {
                TreeNode* temp = bfs.front();
                bfs.pop();
                flag.push_back(temp->val);
                if (temp->left) {
                    bfs.push(temp->left);
                }
                if (temp->right) {
                    bfs.push(temp->right);
                }
            }
            returner.push_back(flag);
        }
        return returner;
    }
};

