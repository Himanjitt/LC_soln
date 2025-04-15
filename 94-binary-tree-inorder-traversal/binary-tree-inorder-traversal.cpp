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
    vector<int> inorderTraversal(TreeNode* root) {
         stack<TreeNode*> st;

        TreeNode* node = root;
        vector<int> ans;

        while (true) {
            // If the current node is not NULL
            if (node != NULL) {
                // Push the current
                // node to the stack
                st.push(node);
                // Move to the left child
                // of the current node
                node = node->left;
            } else {
                // If the stack is empty,
                // break the loop
                if (st.empty()) {
                    break;
                }
                // Retrieve a node from the stack
                node = st.top();
                // Remove the node from the stack
                st.pop();
                // Add the node's value to
                // the inorder traversal list
                ans.push_back(node->val);
                // Move to the right child
                // of the current node
                node = node->right;
            }
        }

        return ans;
    }
};