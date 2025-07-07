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
    int sumNumbers(TreeNode* root) {
        vector<string> paths = allPaths(root);
        int sum = 0;
        for (string str : paths) {
            sum += stoi(str);
        }
        return sum;
    }
    vector<string> allPaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, to_string(root->val));
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string curr) {
        if (!root->left && !root->right) {
            res.push_back(curr);
        }
        if (root->left) {
            helper(root->left, res, curr + to_string(root->left->val));
        }
        if (root->right) {
            helper(root->right, res, curr + to_string(root->right->val));
        }
    }
};
