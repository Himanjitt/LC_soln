class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>mp;
        for(auto ch: s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>, vector<pair<int,char>> > pq;
        
        for(auto it: mp){
            pq.push({it.second,it.first});
        }

        string ans;
        while(!pq.empty()){

            auto ele = pq.top();
            pq.pop();

            while(ele.first--){
                ans += ele.second;
            }
        }

        return ans;
    }
};