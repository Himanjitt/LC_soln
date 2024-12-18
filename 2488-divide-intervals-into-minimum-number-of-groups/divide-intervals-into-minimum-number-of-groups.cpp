class Solution {
public:
    #define p pair<int,int>

    int minGroups(vector<vector<int>>& intervals) {

        vector<p> events;

        for(auto e : intervals) {
            events.push_back({e[0],1});
            events.push_back({e[1]+1,-1});
        }

        sort(events.begin(),events.end());

        int current=0,maxi=INT_MIN;

        for(int i=0;i<events.size();i++){
            current+=events[i].second;
            maxi=max(maxi,current);
        }
        return maxi;
    }
};