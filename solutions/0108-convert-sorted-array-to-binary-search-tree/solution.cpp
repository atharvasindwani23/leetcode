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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(num[num.size() / 2]);
        std::vector<int>left_vec(num.begin(), num.begin() + num.size() / 2);
        std::vector<int>right_vec(num.begin() + num.size() / 2 + 1, num.end());
        root->left = sortedArrayToBST(left_vec);
        root->right = sortedArrayToBST(right_vec);
        return root;
    }
};
