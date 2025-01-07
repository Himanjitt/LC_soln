class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    if(words[j].find(words[i])!=string::npos){
                        ans.insert(words[i]);
                    }
                }
            }
        }
        vector<string>res;
        for(auto it: ans){
            res.push_back(it);
        }
        return res;
    }
};