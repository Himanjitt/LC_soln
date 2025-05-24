
class Solution {
public:
    TreeNode* connector(TreeNode* node) {
        if (node->left == NULL) {
            return node->right;
        }
        if (node->right == NULL) {
            return node->left;
        }

        // Find the rightmost node in the left subtree
        TreeNode* rightmost_in_left = node->left;
        while (rightmost_in_left->right != NULL) {
            rightmost_in_left = rightmost_in_left->right;
        }

        // Connect the right subtree to the rightmost node of left subtree
        rightmost_in_left->right = node->right;

        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* node = root;

        if (node == NULL) {
            return NULL;
        }
        if (node->val == key) {
            return connector(node);
        }
        // searching the key to delete
        while (node) {
            if (node->val > key) {
                if (node->left != NULL && node->left->val == key) {
                    node->left = connector(node->left);
                    return root;
                } else {
                    node = node->left;
                }
            } else {
                if (node->right != NULL && node->right->val == key) {
                    node->right = connector(node->right);
                    return root;
                } else {
                    node = node->right;
                }
            }
        }

        return root;
    }
};