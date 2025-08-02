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
Same to same like count sub array sum equal k
*/
    int count = 0;

    void dfs(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (node == NULL) return ;

        currSum += node->val;
        long long remSum = currSum - targetSum;
        count += prefixSums[remSum];

        // Update prefixSums with current path sum
        prefixSums[currSum]++;

        dfs(node->left, currSum, targetSum, prefixSums);
        dfs(node->right, currSum, targetSum, prefixSums);

        // Backtrack: remove current path sum before returning to parent
        prefixSums[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1; // Base case: one way to reach sum = 0
        dfs(root, 0, targetSum, prefixSums);

        return count;
    } 
};
