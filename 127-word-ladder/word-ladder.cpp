class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        //check notes
        unordered_set<string> st(wordList.begin(), wordList.end());

        int n=beginWord.size();
        if (wordList.size() == 0)
            return 0;
        queue<string> q;
        q.push(beginWord);
        if (beginWord== endWord) {
            return 0;
        }
        vector<char> alpha(26);

        for(int i=0;i<26;i++){
            alpha.push_back(97+i);
        }

        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string node = q.front();
                q.pop();

                if (node == endWord) {
                    return steps;
                }
                for (int i = 0; i < n; i++) {
                    char ch = node[i];
                    for (char it : alpha) {
                        node[i] = it;
                        if (st.count(node) == 1) {
                            q.push(node);
                            st.erase(node);
                        }
                    }
                    node[i] = ch;
                }
            }
            steps++;
        }
        return 0;
    }
};