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
    TreeNode* prev = NULL;
    
    void preorder(TreeNode* curr){
        if(curr == NULL){
            return;
        }

        if(prev){
            prev->right = curr;
            prev->left = NULL;
        }
        TreeNode* rightSub = curr->right;
        prev = curr;
        preorder(curr->left);
        preorder(rightSub);
    }
    void flatten(TreeNode* root) {
        //traverse in preorder way, save the curr node
        //if prevNode is NULL then pass
        //if not NULL then prev -> right will be the curr(note curr is in preorder traversal)
        //prev->left = NULL;
        //before moving curr save the right sub tree by storing it
        //check notes
        TreeNode* prev = NULL;
        preorder(root);

        
    }
};