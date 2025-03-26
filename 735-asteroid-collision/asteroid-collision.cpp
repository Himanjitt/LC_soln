class Solution {
public:
    bool checkOpp(int a, int b) {
        if (a > 0 && b < 0) {
            return true;
        }
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            bool isDestroyed = false;
            while (st.empty() == false && checkOpp(st.top(), asteroids[i])) {
                if (abs(st.top()) == abs(asteroids[i])) {
                    st.pop();
                    isDestroyed = true;
                    break;
                } else if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop();

                } else {
                    isDestroyed = true;
                    break;
                }
            }
            if (isDestroyed == false)
                st.push(asteroids[i]);
        }

        vector<int> ans;
        while (st.empty() == false) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};