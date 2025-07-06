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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(res, root, to_string(root->val));   
        return res;
    }
    void helper(vector<string>& res, TreeNode* root, string t) {
        if (!root->left && !root->right) {
            res.push_back(t);
        }
        if (root->left) {
            helper(res, root->left, t + "->" + to_string(root->left->val)); 
        }
        if (root->right) {
            helper(res, root->right, t + "->" + to_string(root->right->val));
        }
    }
};
