class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos; // Stores {value -> (row, col)}

        // Store positions of each element in mat
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0), colCount(n, 0); // Track marked cells
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = pos[arr[i]]; // Get position of the number
            rowCount[r]++;
            colCount[c]++;

            if (rowCount[r] == n || colCount[c] == m) {
                return i; // Return index when a row or column is completed
            }
        }
        
        return -1; // In case no row or column completes
    }
};
