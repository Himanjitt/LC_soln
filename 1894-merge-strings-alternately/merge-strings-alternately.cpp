class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;
        for(i=0;i<word1.size();i++){
            ans.push_back(word1[i]);
            if(i<word2.size()){
                ans.push_back(word2[i]);
            }
        }

        while(i<word2.size()){
            ans.push_back(word2[i]);
            i++;
        }

        return ans;
    }
};