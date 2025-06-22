class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string token="";

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }
            else if(token != ".."){
                st.push(token);
            }
            //must be ".."
            else if(st.empty() == false){
                st.pop();
            }
        }

        if(st.empty() == true){
            return "/";
        }
        string ans ="";
        while(st.empty() == false){
            ans = '/' + st.top() + ans;
            st.pop();
        }

        return ans;
    }
};