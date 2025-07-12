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
    //LRN -> NRL -> LRN opposite of preorder , reverse at last
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;

        while (curr != NULL) {

            if (curr->right == NULL) {
                ans.push_back(curr->val);
                curr = curr->left;
            } 
            else {
                TreeNode* prev = curr->right;

                while (prev->left != NULL && prev->left != curr) {
                    prev = prev->left;
                }

                if (prev->left == NULL) {// right subtree not visited
                    ans.push_back(curr->val); 
                    prev->left = curr;
                    curr = curr->right;
                } 
                else {                      //right subtree visite
                    curr = curr->left;
                    prev->left = NULL;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};