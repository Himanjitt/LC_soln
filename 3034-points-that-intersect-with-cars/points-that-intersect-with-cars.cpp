class Solution {
public:
    #define p pair<int,int> 
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<p> events;

        for(auto e: nums){
            events.push_back({e[0],1});
            events.push_back({e[1]+1,-1});
        }
        int current=0;
        int totalPoints=0;
        int prev=-1;

        sort(events.begin(),events.end());

        for(auto it: events){
            if(current>0){
                totalPoints+=it.first-prev;
            }

            current+=it.second;
            prev=it.first;
        }
        return totalPoints;
    }
};