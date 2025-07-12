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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;

        while(curr != NULL){
            
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){//left subtree not traversed
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else{                   // left subtree traversed
                    curr=curr->right;
                    prev->right = NULL;
                }
            }
            
        }

        return ans;
    }
};