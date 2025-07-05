class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buyPrice = prices[0];
        for(int i=1;i<n;i++){
            buyPrice = min(buyPrice, prices[i]);
            maxProfit = max(maxProfit,prices[i]-buyPrice);
        }

        return maxProfit;
    }
};