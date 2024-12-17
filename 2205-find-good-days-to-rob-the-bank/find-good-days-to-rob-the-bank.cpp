class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>increasing(n,0);
        vector<int>decreasing(n,0);
        vector<int> ans;

        for(int i=1;i<n;i++){
            if(security[i-1]>=security[i]){
                increasing[i]=increasing[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                decreasing[i]=decreasing[i+1]+1;
            }
        }

        for(int i=time;i<n-time;i++){
            if(decreasing[i]>=time && increasing[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};