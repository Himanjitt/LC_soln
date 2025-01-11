class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;

        for(auto money: accounts){
            int sum=0;
            for(auto ele: money){
                sum+=ele;
            }
            ans=max(ans,sum);
        }

        return ans;
    }
};