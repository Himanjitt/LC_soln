class Solution {
public:
    bool check(string word,string pref){
        int i=0,j=0;
        while(j<pref.size()){
            if(pref[i]!=word[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {

        int count=0;
        for(string word: words){
            if(check(word,pref)==true){
                count++;
            }
        }

        return count;
    }
};