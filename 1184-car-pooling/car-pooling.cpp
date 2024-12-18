class Solution {
public:
    #define p pair<int,int>
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<p>events;

        for(auto e: trips){
            events.push_back({e[1],e[0]});
            events.push_back({e[2],-e[0]});
        }
        
        sort(events.begin(),events.end());

        int current=0;  

        for(auto it: events){
            if(current>capacity){
                return false;
            }
            current+=it.second;
        }
        return true;
    }
};