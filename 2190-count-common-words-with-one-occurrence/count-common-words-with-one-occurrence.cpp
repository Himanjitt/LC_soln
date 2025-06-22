class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int>mp1, mp2;


        for(string s: words1){
            mp1[s]++;
        }
        for(string s: words2){
            mp2[s]++;
        }

        int count = 0;
        for(auto ele: mp1){
            if(ele.second == 1 && mp2[ele.first] == 1){
                count++;
            }
        }

        return count;
    }
};