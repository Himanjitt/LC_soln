class Solution {
public:
    struct trieNode {
        bool endofWord;
        string word;
        vector<trieNode*> children;

        trieNode() {
            endofWord = false;
            word = "";
            children = vector<trieNode*>(26, NULL);
        }
    };

    void insert(trieNode* root, string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            // two cases
            // if char is not present
            if (crawler->children[ch - 'a'] == NULL) {
                crawler->children[ch - 'a'] = new trieNode;
            }
            // if already present move to the next
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endofWord = true;
        crawler->word = word;
    }

    void find(vector<vector<char>>& board, int i, int j, vector<string>&ans, trieNode* root){
        if(i < 0 || i >= board.size() || j<0 || j >= board[0].size()){
            return;
        }
        if(board[i][j] == '#' || root->children[board[i][j] - 'a'] == NULL){
            return;
        }

        root = root->children[ board[i][j] - 'a' ];

        if(root->endofWord == true){
            ans.push_back(root->word);//revert it to false since already found one, but there can
            root->endofWord = false; //be more
        }
        char temp = board[i][j];
        board[i][j] = '#'; //marking visited for current word search

        find(board, i+1,j,ans, root);
        find(board, i-1,j,ans, root);
        find(board, i,j-1,ans, root);
        find(board, i,j+1,ans, root);

        board[i][j] = temp; // unmark after current word search ends
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        
        int m = board.size();
        int n = board[0].size();
        vector<string>ans;
        trieNode* root = new trieNode();

        for (string word : words) {
            insert(root, word);
        }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch = board[i][j];
                if(root->children[ch-'a'] != NULL){
                    find(board,i,j, ans, root);
                }
            }
        }

        return ans;
    }
};