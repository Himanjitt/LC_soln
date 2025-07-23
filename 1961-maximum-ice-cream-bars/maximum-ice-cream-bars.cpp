/*
20
[1,6,3,1,2,5]

 1 1 2 3 5 6

*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i] <= coins){
                ans++;
                coins -= costs[i];
            }
        }

        return ans;
    }
};