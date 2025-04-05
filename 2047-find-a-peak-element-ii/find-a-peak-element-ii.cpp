class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int ans = -1;
        int x = -1, y = -1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    if (mat[i][j] > ans) {
                        x = i, y = j;
                        ans = mat[i][j];
                    }

                } else {
                    if (mat[i][j] > mat[i - 1][j] &&
                        mat[i][j] > mat[i + 1][j] &&
                        mat[i][j] > mat[i][j - 1] &&
                        mat[i][j] > mat[i][j + 1]) {
                        if (mat[i][j] > ans) {
                            x = i, y = j;
                            ans = mat[i][j];
                        }
                    }
                }
            }
        }
        vector<int> v = {x, y};
        return v;
    }
};