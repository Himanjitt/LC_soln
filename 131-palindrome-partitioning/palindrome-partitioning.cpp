class Solution {
public:
    int n;
    bool isPali(int index, int i,string &s){
        int start=index,end=i;

        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    
    void solve(vector<vector<string>>&ans, string &s, int index,vector<string>temp){
        if(index >= s.size()){
            ans.push_back(temp);
        }

        for(int i=index;i<n;i++){
            if(isPali(index,i,s)){
                temp.push_back(s.substr(index,i-index+1));
                solve(ans,s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,s,0,temp);
        return ans;
    }
};