class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasSum=0,costSum=0;
        gasSum=accumulate(gas.begin(),gas.end(),0);
        costSum=accumulate(cost.begin(),cost.end(),0);

        if(costSum>gasSum) return -1;

        int ans=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                ans=i+1;
            }
        }

        return ans;

    }
};