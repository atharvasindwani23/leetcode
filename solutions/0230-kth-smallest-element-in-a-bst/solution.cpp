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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> elements;
        inOrder(elements, root);
        return elements[k  - 1]->val;
    }
    void inOrder(vector<TreeNode*>&elements, TreeNode* root) {
        if (!root) {
            return;
        }
        inOrder(elements, root->left);
        elements.push_back(root);
        inOrder(elements, root->right);
    }
};
