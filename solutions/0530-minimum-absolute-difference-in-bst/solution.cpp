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
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> nodes;
        helper(nodes, root);
        std::sort(nodes.begin(), nodes.end());
        int minimum = nodes[1];
        for (unsigned int i = 0; i < nodes.size() - 1; i++) {
              minimum = min(nodes[i + 1] - nodes[i], minimum);
        }
        return minimum;
    }
    void helper(std::vector<int>& vec, TreeNode* root) {
        if (!root) {
            return;
        }
        vec.push_back(root->val);
        helper(vec, root->left);
        helper(vec, root->right);
    }
};
