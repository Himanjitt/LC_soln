/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while (q.empty() == false) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                data += "#,";
            } else {
                data += to_string(temp->val);
                data += ',';
            }

            if (temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        data.pop_back();
        // for (auto ele : data) {
        //     cout << ele << " ";
        // }
        return data;
    }

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        vector<string> finalData;
        string temp;
        for (char ch : data) {
            if (ch == ',') {
                finalData.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        if (!temp.empty())
            finalData.push_back(temp); // Add the last node

        TreeNode* root = new TreeNode(stoi(finalData[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < finalData.size()) {
            TreeNode* current = q.front();
            q.pop();

            // Left child
            if (finalData[i] != "#") {
                TreeNode* leftNode = new TreeNode(stoi(finalData[i]));
                current->left = leftNode;
                q.push(leftNode);
            }
            i++;

            // Right child
            if (i < finalData.size() && finalData[i] != "#") {
                TreeNode* rightNode = new TreeNode(stoi(finalData[i]));
                current->right = rightNode;
                q.push(rightNode);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));