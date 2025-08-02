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
    // vector of [withRoot, withoutRoot]
    // see neetcode approach
    vector<int> dfs(TreeNode* root){

        if(root == NULL){
            return {0,0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        //if robbing current then we can take child ie no [0]th
        int robThisNode = root->val + left[1] + right[1];
        
        int skipThisNode = max(left[0], left[1]) + max(right[0],right[1]);

        return {robThisNode, skipThisNode};


    }
    int rob(TreeNode* root) {
        vector<int> final = dfs(root);

        return max(final[0], final[1]);
    }
};