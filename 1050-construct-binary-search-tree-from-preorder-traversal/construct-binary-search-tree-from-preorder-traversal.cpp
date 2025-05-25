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
    void buildBST(TreeNode* &root, int key) {
        // searching
        TreeNode* node= root;
        //insertion logic as previosly done
        while (true) {
            if(node->val < key){
                if(node->right== NULL){
                    node->right=new TreeNode(key);
                    break;
                }
                node=node->right;
            }else{
                if(node->left== NULL){
                    node->left=new TreeNode(key);
                    break;
                }
                node=node->left;
            }   
        }       
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            buildBST(root, preorder[i]);
        }
        return root;
    }
};