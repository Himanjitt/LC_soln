class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int servers = 0;
        bool found=false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // col search
                    for (int col = 0; col < n; col++) {
                        if (col!=j && grid[i][col] == 1 ) {
                            servers++;
                            found = true;
                            break;

                        }
                    }
                    // row search
                    if (found == false) {
                        for (int row = 0; row < m; row++) {
                            if (row!=i && grid[row][j] == 1) {
                                servers++;
                                break;
                            }
                        }
                    }
                    found=false;
                }
            }
        }

        return servers;
    }
};