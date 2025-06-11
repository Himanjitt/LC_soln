class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int iS=0, jT=0;
        
        while(jT < t.size()){
            if(s[iS] == t[jT]){
                iS++;
                jT++;
            }else{
                jT++;
            }
        }
        if(iS == s.size()) return true;
        return false;

    }
};