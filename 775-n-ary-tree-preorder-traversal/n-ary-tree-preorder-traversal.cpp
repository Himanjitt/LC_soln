/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void findpre(Node* currNode, vector<int>&ans){
        if(currNode == NULL){
            return;
        }

        ans.push_back(currNode->val);
        for(int i=0;i<currNode->children.size();i++){
            findpre(currNode->children[i], ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        findpre(root, ans);
        return ans;
    }
};