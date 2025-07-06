class TrieNode {
public:
    bool endofWord;
    vector<TrieNode*> children;
    string word;

    TrieNode() {
        endofWord = false;
        children = vector<TrieNode*>(26, nullptr);
        word = "";
    }
};

class Solution {
public:
    TrieNode *root = new TrieNode();

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
        crawler->word = word; 
    }
    
    string search(string word) {
        TrieNode* crawler = root;

        for(char ch : word){
            int index = ch -'a';
            if(crawler->children[index] == NULL){
                return word;
            }
            crawler = crawler->children[index];

            if(crawler->endofWord == true){
                return crawler->word;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string words : dictionary){
            insert(words);
        }

        stringstream ss(sentence);
        string word="";

        string ans ="";
        while(getline(ss, word, ' ')){
            ans += search(word) + ' ';
        }

        ans.pop_back();
        return ans;
        
    }
};