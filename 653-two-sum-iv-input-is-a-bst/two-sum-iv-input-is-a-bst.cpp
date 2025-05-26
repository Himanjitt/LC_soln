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
     unordered_set<int>st;

        void inorder(TreeNode* node, int k, bool &check){
            if(node==NULL){
                return;
            }
            inorder(node->left, k, check);

            if(st.find(k - node->val)!=st.end()){
                check=true;
                return;
            }
            st.insert(node->val);

            inorder(node->right,k, check);
        }

		bool findTarget(TreeNode* root, int k){
            bool check=false;
            inorder(root, k, check);
            return check;
		}
};