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
    unordered_map<int,int>mp;
    int idx;

    // order of postorder is from back 
    // and right call will be made first and then left call
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int rootVal = postorder[idx];
        idx--;
        TreeNode* root = new TreeNode(rootVal);
        
        int pos = mp[rootVal];

        root->right = solve(postorder, inorder, pos+1, end);
        root->left = solve(postorder, inorder, start, pos-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int  n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        int start = 0, end = n-1;
        idx = n-1;
        return solve(postorder, inorder, start, end);
    }
};