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
    bool findTarget(TreeNode* root, int k) {
        std::vector<int> vec;
        helper(vec, root);
        for (int i : vec) {
            std::cout << i << std::endl;
        }
        std::sort(vec.begin(), vec.end());
        int start = 0;
        int end = vec.size() - 1;
        while (start < end) {
           if (vec[start] + vec[end] == k) {
            return true;
           } else if (vec[start] + vec[end] < k) {
            start++;
           } else {
            end--;
           }
        }
        return false;
    }
     void helper(vector<int>&vec, TreeNode* root) {
          if (!root) {
            return;
          }
          vec.push_back(root->val);
          helper(vec, root->left);
          helper(vec, root->right);
    }
};
