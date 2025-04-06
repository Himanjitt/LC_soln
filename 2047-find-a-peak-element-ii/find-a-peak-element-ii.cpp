class Solution {
public:
    int findMaxColIndex(vector<int>& arr) {
        int maxiInd = -1;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
                maxiInd = i;
            }
        }

        return maxiInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int start = 0, end = r - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int maxColIndex = findMaxColIndex(mat[mid]);
            int up = (mid - 1 < 0) ? -1 : mat[mid - 1][maxColIndex];
            int down = (mid + 1 >= r) ? -1 : mat[mid + 1][maxColIndex];
            if (mat[mid][maxColIndex] > up && mat[mid][maxColIndex] > down) {
                return {mid, maxColIndex};
            } else if (down > mat[mid][maxColIndex]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return {-1, -1};
    }
};