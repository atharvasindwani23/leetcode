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
    void flatten(TreeNode* root) {
        if (!root)  {
            return;
        }
        vector<TreeNode*> res;
        preOrder(res, root);
        for (TreeNode* t : res) {
            cout << t->val << endl;
        }
        for (int i  = 0; i < res.size() - 1; i++) {
            TreeNode* curr = res[i];
            TreeNode* next = res[i + 1];
            curr->right = next;
            curr->left = nullptr;
        }
    }
    void preOrder(vector<TreeNode*>& res, TreeNode* root) {
        if (!root) {
            return;
        }
        res.push_back(root);
        preOrder(res, root->left);
        preOrder(res, root->right);
    }
};
