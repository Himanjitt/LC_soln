class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string token;

        string ans;
        while(getline(ss, token, ' ')){
            if(k==0){
                break;
            }

            ans = ans + token + " ";
            k--;
        }

        //remove last space
        ans.pop_back();
        return ans;
        
    }
};