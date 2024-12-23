class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";

        unordered_set<string> st(deadends.begin(), deadends.end());
        if(st.count(start)==1) 
            return -1;
        queue<string> q;
        q.push(start);
        st.insert(start);

        int level = 0;
        while (!q.empty()) {

            int size = q.size();
            while (size--) {
                string node = q.front();
                q.pop();

                if (node == target) {
                    return level;
                }
                for (int i = 0; i < 4; i++) {
                    char ch = node[i];
                    node[i] = (ch == '9') ? '0' : ch + 1;
                    if (st.count(node) == 0) {
                        q.push(node);
                        st.insert(node);
                    }

                    node[i] = (ch == '0') ? '9' : ch - 1;
                    if (st.count(node) == 0) {
                        q.push(node);
                        st.insert(node);
                    }

                    node[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }
};