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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     vector<vector<int>> res;
     vector<vector<int>> returner;
     if (!root) {
        return {};
     }
     vector<int> curr = {root->val};
     helper(res, root, curr);
     for (vector<int> vec : res) {
        if (sum(vec) == targetSum) {
            returner.push_back(vec);
        }
     }
     return returner;
    }
    void helper(vector<vector<int>>& res, TreeNode* root, vector<int>& curr) {
        if (!root->left && !root->right) {
            res.push_back(curr);
            cout << "meow" << endl;
            return;
        }
        if (root->left) {
             curr.push_back(root->left->val);
            helper(res, root->left, curr);
            curr.pop_back();
        }
        if (root->right) {
            curr.push_back(root->right->val);
            helper(res, root->right, curr);
            curr.pop_back();
        }
    }
    int sum(vector<int> vec) {
        int s = 0;
        for (int i : vec) {
            std::cout << i << std::endl;
            s+= i;
        }
        cout << "end" << endl;
        return s;
    }
};
