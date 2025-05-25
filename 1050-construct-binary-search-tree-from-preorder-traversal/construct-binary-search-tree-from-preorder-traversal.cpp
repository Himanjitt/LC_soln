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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
        if(start>end){
            return NULL;
        }
        int rootVal=preorder[idx];
        idx++;
        int i;
        for( i=start;i<=end;i++){
            if(rootVal==inorder[i]){
                break;
            }
        }
        TreeNode* root=new TreeNode(rootVal);

        root->left=solve(preorder,inorder, start, i-1, idx);
        root->right=solve(preorder, inorder, i+1, end, idx);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=preorder.size();
        int start=0;
        int end=n-1;
        int idx=0;
        return solve(preorder,inorder, start, end, idx);
    }
};