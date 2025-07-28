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
class Solution {
public:
    // same as the question same in leetcode, just one extra step
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q== NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);

        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true; // An empty tree is always a subtree
        }
        if (root == nullptr) {
            return false; // Non-empty tree can't be a subtree of an empty tree
        }
        // Check if the current trees are identical or if the subtree exists in
        // the left or right subtree
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};