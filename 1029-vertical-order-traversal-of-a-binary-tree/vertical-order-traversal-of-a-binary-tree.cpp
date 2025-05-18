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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        // queue_of_node_and_vertical position with level position
        queue<pair<TreeNode*, pair<int, int>>> q;
        // map to store the key as vertical and value as level and the nodes
        //  in sorted order
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (q.empty() == false) {
            auto p = q.front();
            q.pop();
            int x = p.second.first;
            int y = p.second.second;
            TreeNode* node = p.first;
            mp[x][y].insert(node->val);

            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        for (auto ele : mp) {
            vector<int> column;
            for (auto it : ele.second) {
                for (int value : it.second) {
                    column.push_back(value);
                }
            }
            ans.push_back(column);
        }
        return ans;
    }
};