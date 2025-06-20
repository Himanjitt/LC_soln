class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string temp ="";
                while(st.top() != '['){
                    char top = st.top();
                    st.pop();
                    //remember not temp = temp + top
                    //then we have to reverse
                    temp = top + temp;
                }
                st.pop();

                //find number
                string num ="";

                while(st.empty() == false && st.top() >= '0' && st.top() <= '9'){
                    char top = st.top();
                    st.pop();
                    //remember not temp = temp + top
                    //then we have to reverse
                    num = top + num;
                }
                int number = stoi(num);

                string ktimes="";
                while(number--){
                    ktimes += temp;
                }
                for(int i=0; i<ktimes.size() ;i++){
                    st.push(ktimes[i]);
                }
            }
        }

        string ans="";
        while(st.empty() == false){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};