/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

int height(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int L=1+height(root->left);
    int R=1+height(root->right);

    return max(L,R);
    
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = height(root);
        return ans;
    }
};