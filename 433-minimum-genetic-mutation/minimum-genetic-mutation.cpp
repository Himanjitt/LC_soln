class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        if(bank.size()==0) return -1;
        queue<string> q;
        q.push(startGene);
        if (startGene == endGene) {
            return 0;
        }
        vector<char> genes = {'A', 'C', 'G', 'T'};

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string node = q.front();
                q.pop();

                if (node == endGene) {
                    return steps;
                }
                for (int i = 0; i < 8; i++) {
                    char ch = node[i];
                    for (char it : genes) {
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
        return -1;
    }
};