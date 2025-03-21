/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       std::map<TreeNode*, TreeNode*> parentMap;
       parentMap[root] = nullptr;
       parentMapMaker(root, parentMap);
       std::vector<TreeNode*> p_path;
       std::vector<TreeNode*> q_path;
       TreeNode* copy = p;
       while (copy != nullptr) {
         p_path.push_back(copy);
         copy = parentMap[copy];
       }
       copy = q;
       while (copy != nullptr) {
        q_path.push_back(copy);
        copy = parentMap[copy];
       }
       for (TreeNode* i : q_path) {
        for (TreeNode* j : p_path) {
            if (i->val == j -> val) {
                return i;
            }
        }
       }
       return nullptr;
     }
     void parentMapMaker(TreeNode* root, std::map<TreeNode*, TreeNode*>& parent) {
         if (!root) {
            return;
         }
         if (root->left) {
            parent[root->left] = root;
         }
         if (root->right) {
            parent[root->right] = root;
         }
         parentMapMaker(root->left, parent);
         parentMapMaker(root->right, parent);
     }
};
