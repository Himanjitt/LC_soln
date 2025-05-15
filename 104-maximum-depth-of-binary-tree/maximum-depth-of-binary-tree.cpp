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
    int solve(TreeNode* curr){
        if(curr==NULL){
            return 0;
        }
        int ans=max(1+solve(curr->left),1+solve(curr->right));
        return ans;
    }
    int maxDepth(TreeNode* root) {
        return solve(root);

    }
};