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
    void preorder(TreeNode* node, vector<int>&numbers, int num){
        
        if(node == NULL){
            return;
        }

        if(node->left == NULL && node->right == NULL){
            num = num * 10 + node->val;
            numbers.push_back(num);
            return;
        }

        num = num * 10 + node->val;
        preorder(node->left, numbers, num);
        preorder(node->right, numbers, num);
    }
    int sumNumbers(TreeNode* root) {
        vector<int>numbers;
        preorder(root, numbers, 0);

        int ans = accumulate(numbers.begin(), numbers.end(),0);
        return ans;
    }
};