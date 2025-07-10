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
    int solve(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        if(node->left == NULL){
            return 1 + solve(node->right);
        }

        if(node->right == NULL){
            return 1 + solve(node->left);
        }

        int left = 1 + solve(node->left);
        int right = 1 + solve(node->right);

        return min(left, right);

    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return solve(root);
    }
};