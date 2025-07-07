class Solution {
public:
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        left(root);
        return sum;
    }
    
    void left(TreeNode* root){
        if(root==NULL) return;
        if(root->left &&!root->left->left && !root->left->right) sum+=root->left->val;
        left(root->left);
        left(root->right);
    }
};
