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
    void findpost(Node* currNode, vector<int>&ans){
        if(currNode == NULL){
            return;
        }

        for(int i=0;i<currNode->children.size();i++){
            findpost(currNode->children[i], ans);
        }
        ans.push_back(currNode->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        findpost(root, ans);
        return ans;
    }
};