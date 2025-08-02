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
/*
we are doing dfs call for every n nodes
there O(n^2)
*/
    int count =0;
    
    void dfs(TreeNode* node, int target, long long currSum){
        if(node == NULL){
            return;
        }

        currSum += node->val;

        if(currSum == target){
            count++;
        }

        dfs(node->left, target, currSum);
        dfs(node->right, target, currSum);
    }

    void preorder(TreeNode* node, int target){
        if(node == NULL){
            return;
        }

        long long currSum = 0;
        dfs(node, target, currSum);
        preorder(node->left, target);
        preorder(node->right, target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return count;
        preorder(root, targetSum);

        return count;
    }
};