//CHECK NOTES
class Solution {
public:
    // BS on getnext
    int getNext(vector<vector<int>>& jobs, int index) {
        int start = index + 1, end = jobs.size() - 1;
        //important to intialize, incase no valid is found then
        // it will redirect to ending index
        int ans = jobs.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (jobs[index][1] < jobs[mid][0]) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& jobs, int i, vector<vector<int>>&dp, int k) {
        // base case
        if (i == jobs.size()) {
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        // not take
        int notTake = solve(jobs, i + 1, dp, k);

        // take
        int indOfNextJob = getNext(jobs, i);
        int take = 0;
        if(k > 0){
            take = jobs[i][2] + solve(jobs, indOfNextJob, dp, k-1);
        }   

        return dp[i][k] = max(notTake, take);
    }
    int maxValue(vector<vector<int>>& jobs, int k) {
        int size = jobs.size();
        sort(jobs.begin(), jobs.end());
        vector<vector<int>>dp(size,vector<int>(k+1,-1));
        return solve(jobs, 0, dp, k);
    }
};