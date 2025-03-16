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
    std::map<TreeNode*, TreeNode*> parentNodes;
    parentNodes[root] = NULL;
    map_returner(root, parentNodes);
    std::vector<int> p_parents;
    std::vector<int> q_parents;
    while (p != nullptr) {
        std::cout << p->val << std::endl;
        p_parents.push_back(p->val);
        p = parentNodes[p];
    }
    while ( q != nullptr) {
        std::cout << q->val << std::endl;
        q_parents.push_back(q->val);
        q = parentNodes[q];
    }
     for (int i : p_parents) {
        for (int j : q_parents) {
            if (i == j) {
                return (new TreeNode(i));
            }
        }
     }
     std::cout << "this then?" << std::endl;
     return nullptr;
    }


     void map_returner(TreeNode* root, std::map<TreeNode*, TreeNode*> &map) {
       if (!root) {
        std::cout << "this??" << std::endl;
        return;
       }
       if (root->left && root->right) {
        map[root->left] = root;
        map[root->right] = root;
        } else {
            if (root->left) {
                map[root->left] = root;
            } else if (root->right) {
                map[root->right] = root;
            } else {
                return;
            }
        }
        map_returner(root->left, map);
        map_returner(root->right, map);
     }
};
