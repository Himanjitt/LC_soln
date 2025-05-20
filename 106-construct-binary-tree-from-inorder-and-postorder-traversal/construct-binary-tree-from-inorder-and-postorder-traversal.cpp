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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start, int end, int &idx){
        if(start>end) return NULL;

        int rootVal=postorder[idx];
        idx--;
        int i;

        for(i=start;i<=end;i++){
            if(rootVal==inorder[i]){
                break;
            }
        }

        TreeNode* root=new TreeNode(rootVal);
        
        root->right=solve(inorder, postorder, i+1, end, idx);
        root->left=solve(inorder, postorder, start, i-1, idx);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int start=0, end=n-1;
        int idx=n-1;
        return solve(inorder, postorder, start, end, idx);
    }
};