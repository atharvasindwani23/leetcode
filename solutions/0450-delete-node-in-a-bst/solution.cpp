class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*& deleted = find(root, key);
        if (!deleted) return root; // If the node doesn't exist, return the tree unchanged

        // Case 1: Node is a leaf
        if (!deleted->left && !deleted->right) {
            delete deleted;
            deleted = nullptr;
        }
        // Case 2: Node has only right child
        else if (!deleted->left) {
            TreeNode* temp = deleted;
            deleted = deleted->right;
            delete temp;
        }
        // Case 3: Node has only left child
        else if (!deleted->right) {
            TreeNode* temp = deleted;
            deleted = deleted->left;
            delete temp;
        }
        // Case 4: Node has two children
        else {
            TreeNode* predecessor = deleted->left;
            while (predecessor->right) {
                predecessor = predecessor->right;
            }
            deleted->val = predecessor->val;
            deleted->left = deleteNode(deleted->left, predecessor->val);
        }
        return root;
    }

    TreeNode*& find(TreeNode*& root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        if (val < root->val) {
            return find(root->left, val);
        } else {
            return find(root->right, val);
        }
    }
};

