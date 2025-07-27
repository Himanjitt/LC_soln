class Solution {
public:
    static bool cmp(pair<int,char> &a, pair<int,char> &b){
        if(a > b){
            return true;
        }

        return false;
    }
    string frequencySort(string s) {
        unordered_map<int,int>mp;
        for(auto ch: s){
            mp[ch]++;
        }

        vector<pair<int, char>>v;

        for(auto it: mp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), cmp);

        for(auto ele : v){
            cout<< ele.first<<" "<< ele.second<<endl;
        }
        string ans;

        for(auto ele : v){
            while(ele.first--){
                ans += ele.second;
            }
        }

        return ans;
    }
};