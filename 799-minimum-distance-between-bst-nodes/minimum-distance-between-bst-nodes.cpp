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
    void inorder(TreeNode* node, int &mini, TreeNode* &prev){
        if(node == NULL){
            return;
        }
        inorder(node->left, mini, prev);
        if(prev != NULL){
            mini=min(mini, abs(node->val - prev->val));
        }
        prev=node;
        inorder(node->right, mini, prev);
    }
    int minDiffInBST(TreeNode* root) {
       if(root == NULL){
            return 0;
        }

        TreeNode* node = root;
        TreeNode* prev = NULL;
        int mini=INT_MAX;
        inorder(node, mini, prev);
        return mini; 
    }
};