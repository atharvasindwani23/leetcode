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
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sums = levelSum(root);
        int res = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < level_sums.size(); i++) {
            if (level_sums[i] > maxi) {
                maxi = level_sums[i];
                res = i;
            }
        }
        return res + 1;
    }
 
    //can do a level order traversal => can return a vector which will have level order sums for all

    vector<int> levelSum(TreeNode* root) {
        queue<TreeNode*> elements;
        vector<int> result;
        elements.push(root);

        while (!elements.empty()) {
            int size = elements.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = elements.front();
                sum += curr->val;
                elements.pop();
                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
            result.push_back(sum);
        }
        return result;
    }

};
