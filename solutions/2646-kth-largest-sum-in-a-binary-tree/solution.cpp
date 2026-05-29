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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        vector<long long> levelSum;
        queue<TreeNode*> elements;
        elements.push(root);

        while (!elements.empty()) {

            int len = elements.size();

            for (int i = 0; i < len; i++) {
                TreeNode* curr = elements.front();
                elements.pop();
                sum += curr->val;
                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
            levelSum.push_back(sum);
            sum = 0;
        }
        sort(levelSum.begin(), levelSum.end());
        reverse(levelSum.begin(), levelSum.end());
        if (levelSum.size() < k) {
            return -1;
        }
        return levelSum[k - 1];
    }

    //brute force approach is to calculate the sum of the elements at each level and store it in an array then return arr[k]
};
