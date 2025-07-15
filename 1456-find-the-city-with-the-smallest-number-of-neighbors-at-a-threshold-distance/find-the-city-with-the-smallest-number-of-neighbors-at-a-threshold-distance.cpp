class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd warshall
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0;
        }
        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (SPM[i][via] != INT_MAX && SPM[via][j] != INT_MAX)
                        SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }

        int minCity = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cityCount = 0;
            for (int j = 0; j < n; j++) {
                if (SPM[i][j] <= distanceThreshold) {
                    cityCount++;
                }
            }
            if (cityCount <= minCount) {
                minCount = cityCount;
                minCity = i;
            }
        }

        return minCity;
    }
};