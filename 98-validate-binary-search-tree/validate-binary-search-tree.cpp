/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* node, long mini, long maxi) {
        if (node == NULL)
            return true;

        if (node->val >= maxi || node->val <= mini) {
            return false;
        }

        bool leftCheck = check(node->left, mini, node->val);
        bool rightCheck = check(node->right, node->val, maxi);

        return leftCheck && rightCheck;
    }
    bool isValidBST(TreeNode* root) { 
        return check(root, LONG_MIN, LONG_MAX); 
    }
};