// CHECK NOTES
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

            if (jobs[index][1] <= jobs[mid][0]) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    long long solve(vector<vector<int>>& jobs, int i, vector<long long>&dp) {
        // base case
        if (i == jobs.size()) {
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        // not take
        long long  notTake = solve(jobs, i + 1, dp);

        // take
        int indOfNextJob = getNext(jobs, i);
        long long take = (jobs[i][1] - jobs[i][0]) + jobs[i][2] + solve(jobs, indOfNextJob, dp);;


        return dp[i] = max(notTake, take);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& jobs) {
        int size = jobs.size();
        sort(jobs.begin(), jobs.end());
        vector<long long>dp(size, -1);
        return solve(jobs, 0, dp);
    }
};