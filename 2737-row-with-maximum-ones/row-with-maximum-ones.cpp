class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int ansind = -1;
        int maxSum = INT_MIN;
        vector<int> ans;
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < c; j++) {
                sum += mat[i][j];
            }
            if (sum > maxSum) {
                ansind = i;
                maxSum = sum;
                
            }
        }
        ans.push_back(ansind);
        ans.push_back(maxSum);
        return ans;
    }
};