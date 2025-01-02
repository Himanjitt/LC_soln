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
    void dfs(TreeNode* root, int &count, vector<int> &hash) {
        if (root==NULL) return;

        // Increment the count of the current node's value in the hash
        hash[root->val]++;

        // If it's a leaf node, check for pseudo-palindromic condition
        if (!root->left && !root->right) {
            int odds = 0;
            for (int num : hash) {
                if (num % 2 == 1) odds++;
            }
            if (odds <= 1) count++;
        }

        // Recursive calls for left and right children
        if (root->left) dfs(root->left, count, hash);
        if (root->right) dfs(root->right, count, hash);

        // Backtrack: undo the increment of the current node's value
        hash[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>hash(10,0);
        int count=0;
        dfs(root,count,hash);

        return count;
    }
};