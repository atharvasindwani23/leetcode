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
    bool isValidBST(TreeNode* root) {
     vector<int> res;
     helper(res, root);
     for (int i = 0; i < res.size()  - 1; i++) {
        cout << res[i] << endl;
        if (res[i] >= res[i + 1]) {
            return false;
        }
     }
     return true;
    }
    void helper(vector<int>& res, TreeNode* root) {
        if (!root) {
            return;
        }
        helper(res, root->left);
        res.push_back(root->val);
        helper(res, root->right);
    }
};
