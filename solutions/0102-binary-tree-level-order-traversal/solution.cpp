class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> returner;
        if (!root) {
            return returner;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> flag;
            for (int i = 0; i < size; i++) {
              TreeNode* temp = q.front();
              if (temp->left) {
                q.push(temp->left);
              }
              if (temp->right) {
                q.push(temp->right);
              }
              q.pop();
              flag.push_back(temp->val);
            }
            returner.push_back(flag);
        }
        return returner;
    }
};

