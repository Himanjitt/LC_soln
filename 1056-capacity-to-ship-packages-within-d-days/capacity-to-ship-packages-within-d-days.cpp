class Solution {
public:
    bool isValid(vector<int>& weights, int mid, int days) {
        int sum=0;
        int k=1;
        for(int i=0;i<weights.size();i++){
            if(sum + weights[i] <= mid){
                sum+=weights[i];
                continue;
            }
            k++;
            sum=weights[i];
        }
        
        if(k<=days) return true;

        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()),
            r = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (isValid(weights, mid, days) == true) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};