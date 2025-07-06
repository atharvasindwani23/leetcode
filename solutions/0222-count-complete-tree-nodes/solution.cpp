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
    int countNodes(TreeNode* root) {
        vector<int> res;
        vector<int> meow = level(root);
        int sum = 0;
        for (int i  : meow) {
            sum += i;
        }
        //helper(root, res);
        return sum;
    }

    void helper(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }



//try developing a helper function which returns how many nodes are there in each level
    vector<int> level(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return {};
        }
        res.push_back(1);
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        int d = 0;
        while (!q.empty()) {
            for (int i  = 0; i < c; i++) {
            TreeNode* x = q.front();
            q.pop();
            if (x->left) {
                q.push(x->left);
                d++;
            }
            if (x->right) {
                q.push(x->right);
                d++;
            }
            }
            if (d == 0) {
                break;
            }
            
            res.push_back(d);
            c = d;
            d = 0;
        }
        return res;
    }




    //2^(h - 1) - 1 + (number of nodes on the last level)
    //finding height is easy

};
