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
    void solve(TreeNode* node, string temp, vector<string>& ans){
            if(node==NULL){
                return;
            }
            temp+=to_string(node->val);
            if(node->left==NULL && node->right==NULL){
                ans.push_back(temp);
            }
            if(node->left){
                solve(node->left,temp + "->",ans);
            }
            if(node->right){
                solve(node->right,temp + "->",ans);
            }
            temp.pop_back();
        }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
            string temp;
            solve(root,temp,ans);
            return ans;
    }
};