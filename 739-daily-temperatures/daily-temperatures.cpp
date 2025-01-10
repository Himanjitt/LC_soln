class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (s.empty() == false && temperatures[s.top()] < temperatures[i]) {
                v[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            if (v[i] != 0) {
                v[i] = v[i] - i;
            }
        }

        return v;
    }
};