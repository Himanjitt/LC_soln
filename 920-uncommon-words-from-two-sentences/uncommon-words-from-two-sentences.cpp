class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s3 = s1 + " " + s2;
        map<string,int>mp;

        stringstream ss(s3);
        string token;

        while(getline(ss, token, ' ')){
            mp[token]++;
        }

        vector<string>ans;

        for(auto ele: mp){
            if(ele.second == 1){
                ans.push_back(ele.first);
            }
        }

        return ans;
    }
};