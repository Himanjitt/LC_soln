//DP + BINARY SEARCH
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

    int solve(vector<vector<int>>& jobs, int i, vector<int>&dp) {
        // base case
        if (i == jobs.size()) {
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        // not take
        int notTake = solve(jobs, i + 1, dp);

        // take
        int indOfNextJob = getNext(jobs, i);
        int take = jobs[i][2] + solve(jobs, indOfNextJob, dp);

        return dp[i] = max(notTake, take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<vector<int>> jobs;
        int size = startTime.size();
        for (int i = 0; i < size; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        vector<int>dp(size, -1);
        return solve(jobs, 0, dp);
    }
};