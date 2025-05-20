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
    unordered_map<int, TreeNode*> mp;

    void solve(TreeNode* node) {
        if (node == NULL)
            return;

        if (node->left) {
            mp[node->left->val] = node;
        }
        if (node->right) {
            mp[node->right->val] = node;
        }
        solve(node->left);
        solve(node->right);
    }
    TreeNode* findNode(TreeNode* root, int start) {
        if (!root)
            return NULL;
        if (root->val == start)
            return root;

        TreeNode* left = findNode(root->left, start);
        if (left)
            return left;

        return findNode(root->right, start);
    }

    void bfs(TreeNode* target, int& ans) {
        unordered_set<int> visited;
        visited.insert(target->val);
        queue<TreeNode*> q;
        q.push(target);

        while (q.empty() == false) {
            int size = q.size();
            ans++;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != NULL && visited.count(temp->left->val) == 0) {
                    visited.insert(temp->left->val);
                    q.push(temp->left);
                }
                if (temp->right != NULL &&
                    visited.count(temp->right->val) == 0) {
                    visited.insert(temp->right->val);
                    q.push(temp->right);
                }

                if (mp.count(temp->val) != 0 &&
                    visited.count(mp[temp->val]->val) == 0) {
                    visited.insert(mp[temp->val]->val);
                    q.push(mp[temp->val]);
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root);
        int ans = 0;
        TreeNode* startAddress =
            (start == root->val) ? root : findNode(root, start);
        bfs(startAddress, ans);
        return ans - 1;
    }
};