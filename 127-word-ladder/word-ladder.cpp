class Solution {
public:
    int ladderLength(string startWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        // endword is not present
        if (st.find(endWord) == st.end())
            return 0;

        // startWord == endword
        if (startWord == endWord)
            return 0;

        queue<string> q;
        q.push(startWord);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            while (size--) {
                string front = q.front();
                q.pop();

                if (front == endWord)
                    return level;

                for (int i = 0; i < front.size(); i++) {
                    char letter = front[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        front[i] = ch;
                        if (st.find(front) != st.end()) {
                            q.push(front);
                            st.erase(front);
                        }
                    }
                    front[i] = letter;
                }
            }
            
        }

        return 0;
    }
};