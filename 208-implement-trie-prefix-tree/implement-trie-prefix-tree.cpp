class TrieNode {
public:
    bool endofWord;
    vector<TrieNode*> children;

    TrieNode() {
        endofWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* crawler = root;

        for(char ch : word){
            int index = ch -'a';
            if(crawler->children[index] == NULL){
                crawler->children[index] = new TrieNode();
            }
            crawler = crawler->children[index];
        }
        crawler->endofWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(char ch : word){
            int index = ch -'a';
            if(crawler->children[index] == NULL){
                return false;
            }
            crawler = crawler->children[index];
        }
        return crawler->endofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(char ch : prefix){
            int index = ch -'a';
            if(crawler->children[index] == NULL){
                return false;
            }
            crawler = crawler->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */