class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        int uncountedClose=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(st.empty()==false && st.top()=='('){
                st.pop();
            }
            else{
                uncountedClose++;
            }
        }

        return st.size()+uncountedClose;
    }
};