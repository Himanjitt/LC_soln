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

/*
        -1:->1:9
         0:->0:3
             2:15
         1:->1:20
         2:->2:7

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // we will store the x axis and y axis in sorted order
        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            mp[x][y].insert(node->val);

            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto ele : mp) {
            vector<int> column;
            for (auto it : ele.second) {
                for(auto it2 : it.second){
                    column.push_back(it2);
                }
            }
            ans.push_back(column);
        }
        return ans;
    }
};

/*
        -1:->1:9
         0:->0:3
             2:15
         1:->1:20
         2:->2:7

*/