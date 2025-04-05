class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for (auto vec : mat) {
            int start = 0, end = vec.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (vec[mid] == target) {
                    return true;
                } else if (vec[mid] > target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};
