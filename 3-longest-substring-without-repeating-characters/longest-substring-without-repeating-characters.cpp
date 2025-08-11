class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int left = 0, right = 0;
        int n = s.size();

        unordered_set<int> st;
        int maxlen = 1;

        while(right < n){
            
            //shrink
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            int len = right - left + 1;
            maxlen = max(maxlen, len);
            right ++;
        }

        return maxlen;
    }
};