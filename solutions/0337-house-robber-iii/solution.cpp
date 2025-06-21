class Solution {
public:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        // Left and right subtrees
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // If we rob this node, we cannot rob its children
        int rob = node->val + left.second + right.second;

        // If we don't rob this node, we take the max of robbing or not robbing children
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

