class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);  
        string token;
        string result;

        while (getline(ss, token , ' ')) {
            reverse(token.begin(), token.end());  
            result+=token + " "; 
        }
        result.pop_back();
        return result; 
     
    }
};
