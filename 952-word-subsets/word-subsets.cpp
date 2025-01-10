class Solution {
public:
    bool isSubset(vector<int>&temp, vector<int>&freq2){
        for(int i=0;i<freq2.size();i++){
            if(temp[i]<freq2[i]){
                return false;
            }
        }

        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> freq2(26,0);

        for(string word: words2){
            vector<int> temp(26,0);
            for(char ch: word){
                temp[ch-'a']++;

                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }
        vector<string> ans;
        for(string word: words1){
            vector<int>temp(26,0);
            for(char ch: word){
                temp[ch-'a']++;
            }
            if(isSubset(temp,freq2)==true){
                ans.push_back(word);
            }
        }

        return ans;
    }
};