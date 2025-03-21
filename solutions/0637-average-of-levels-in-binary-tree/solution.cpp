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
    vector<double> averageOfLevels(TreeNode* root) {
     std::queue<TreeNode*> bfs;
     std::vector<double> returner; //[sum of elements in the vector] /sizeof(vector);
     bfs.push(root);
     double sum = 0;
     while (!bfs.empty()) {
        double sizeQ = bfs.size();
        for (int i = 0; i < sizeQ; i++) {
            TreeNode* temp = bfs.front();
            bfs.pop();
          if (temp->left) {
            bfs.push(temp->left);
          }
          if (temp->right) {
            bfs.push(temp->right);
          }
          sum += temp->val;
        }
        std::cout << sum << std::endl;
        double average = (sum) / sizeQ;
        returner.push_back(average);
        std::cout << sizeQ << std::endl;
        sum = 0;
     }
     return returner;
   }
};
