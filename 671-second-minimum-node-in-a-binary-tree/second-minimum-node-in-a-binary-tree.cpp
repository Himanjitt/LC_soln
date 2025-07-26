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
    void solve(TreeNode* node, int firstMini,int &secondMini, bool &flag){
        if(node == NULL){
            return;
        }

        if(node->val > firstMini){
            secondMini = min(secondMini, node->val);
            flag = true;
        }
        

        solve(node->left, firstMini, secondMini, flag);
        solve(node->right,firstMini, secondMini, flag);
    }

    //using flag for edge case of INT_MAX
    int findSecondMinimumValue(TreeNode* root) {
        int secondMini = INT_MAX;
        int firstMini = root->val;
        bool flag = 0;
        solve(root, firstMini, secondMini, flag);
        
        if(flag == 0){
            return -1;
        }
        return secondMini;
    }
};