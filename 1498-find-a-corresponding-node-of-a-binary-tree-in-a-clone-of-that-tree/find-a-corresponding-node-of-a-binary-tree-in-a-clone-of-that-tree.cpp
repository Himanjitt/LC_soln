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
    TreeNode* dfs(TreeNode* root, int search) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == search)
            return root;
        // Check the left subtree
        TreeNode* leftResult = dfs(root->left, search);
        if (leftResult != NULL) {
            return leftResult;
        }
        // Check the right subtree
        TreeNode* rightResult = dfs(root->right, search);
        if (rightResult != NULL) {
            return rightResult;
        }

        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        int search = target->val;

        return dfs(cloned, search);
    }
};