/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //logic obvious; just get a normal level order traversal and reverse it
        
        vector<vector<int>> traversal;
        if (!root) {
            return {};
        }
        queue<TreeNode*> elements;
        elements.push(root);

        while (!elements.empty()) {
            int length = elements.size();
            vector<int> level;
            for (int i = 0; i < length; i++) {
                TreeNode* curr = elements.front();
                elements.pop();
                level.push_back(curr->val);
                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
            traversal.push_back(level);
            level.clear();
        }
        reverse(traversal.begin(), traversal.end());
        return traversal;
    }
};
