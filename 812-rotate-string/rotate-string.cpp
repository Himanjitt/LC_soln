class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++){
            s+=s[i];
            string check=s.substr(i+1,n+1);
            if(check==goal){
                return true;
            }
        }
        return false;
    }
};