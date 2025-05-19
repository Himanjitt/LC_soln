/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    unordered_map<int, TreeNode*> mp;

    void solve(TreeNode* node) {
        if (node == NULL) return;

        if (node->left) {
            mp[node->left->val] = node;
        }
        if (node->right) {
            mp[node->right->val] = node;
        }
        solve(node->left);
        solve(node->right);
    }

    void bfs(TreeNode* target, int k, vector<int>& ans) {
        unordered_set<int> visited;
        visited.insert(target->val);
        queue<TreeNode*> q;
        q.push(target);

        while (q.empty() == false) {
            int size = q.size();
            if (k == 0) break;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != NULL &&
                    visited.count(temp->left->val) == 0) {
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
             k--;
        }

        while (q.empty() == false) {
            TreeNode* valNode = q.front();
            q.pop();
            ans.push_back(valNode->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // make the node traversable to up
        solve(root);
        vector<int> ans;
        bfs(target, k, ans);
        // for(auto it:mp){
        //     cout<<it.first<<" :"<<it.second<<endl;
        // }
        return ans;
    }
};