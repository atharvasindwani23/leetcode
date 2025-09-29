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
    bool isCompleteTree(TreeNode* root) {
        if (!isValidTree(root)) {
            return false;
        }
        map<int, vector<TreeNode*>> flag;
        levelOrderTraversal(root, flag);
        vector<TreeNode*> vec = flag[height(root) - 1];
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] == nullptr && vec[i + 1] != nullptr) {
                return false;
            }
        }
        return true;
    }   


    bool isValidTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int c = q.size();
            cout << c << endl;
            for (int i = 0; i < c; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
                if (c != (int)pow(2, level)) {
                    return (level == height(root) - 1);
                }
            }
            level++;
            }
            return true;
        }

        int height(TreeNode* root) {
            if (!root) {
                return 0;
            }
            return max(height(root->left) + 1, height(root->right) + 1); 
        }

            void levelOrderTraversal(TreeNode* root, std::map<int, std::vector<TreeNode*>>& levels) {
    if (!root) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root); // Start the BFS with the root node.
    int level = 0;
    
    // We don't need to dynamically allocate 'val' since the problem with 
    // isCompleteTree check is typically done by pushing a real 'nullptr'.
    // However, since the goal is to *save* placeholders in the map, and 
    // the problem code used a dummy node, we'll revert to the standard 
    // and more efficient practice of pushing 'nullptr' into the vector, 
    // which is what 'std::vector<TreeNode*>' is designed for.

    // A flag to indicate that we've encountered a nullptr.
    // In a complete tree check, any non-null node after this means it's not complete.
    bool found_null = false; 

    while (!q.empty()) {
        int c = q.size();
        std::vector<TreeNode*> elements;
        
        // This loop processes all nodes currently at the front of the queue (the current level)
        for (int i = 0; i < c; i++) {
            TreeNode* curr = q.front();
            q.pop();

            // Store the current node's pointer in the level vector.
            elements.push_back(curr);

            // If we hit a null node, we stop processing its children (it has none).
            if (curr == nullptr) {
                // Once we see a null, the 'found_null' flag remains true for the rest of the traversal.
                found_null = true; 
                continue;
            }

            // Check if a non-null node appeared AFTER a null node (used for completeness check)
            if (found_null) {
                // If any non-null node (curr) is found after a null node was found (found_null is true),
                // the tree is definitively NOT complete, but we continue the traversal to fill the map
                // if we are required to capture the entire structure.
            }
            
            // Push children, including explicit nullptr placeholders, into the queue for the next level
            q.push(curr->left);
            q.push(curr->right);
        }
        
        // Save the level's elements (including the null placeholders) to the map
        levels[level] = elements;

        // CRITICAL FIX: The loop condition was incorrectly pushing 'root' inside the 'while' loop,
        // causing an infinite loop. This has been removed in this rewrite.
        
        level++;
    }
}
        

};
