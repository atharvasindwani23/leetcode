class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> returner;
        if (!root) return returner;

        queue<TreeNode*> elements;
        elements.push(root);

        while (!elements.empty()) {
            int size = elements.size(); // Number of nodes at current level
            vector<int> part;
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = elements.front();
                elements.pop();
                
                part.push_back(temp->val);
                
                if (temp->left) elements.push(temp->left);
                if (temp->right) elements.push(temp->right);
            }
            
            returner.push_back(part);
        }

        return returner;
    }
};

