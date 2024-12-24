class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 1e9));

        for (int i = 1; i < n; i++) {
            adjMat[i][i + 1] = 1;
            adjMat[i + 1][i] = 1;
        }

        adjMat[x][y] = 1;
        adjMat[y][x] = 1;

        // FloydWarshall

        for (int house = 1; house <= n; house++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(i==j){
                        adjMat[i][j]=0;
                        continue;
                    }
                    adjMat[i][j] =
                        min(adjMat[i][j], adjMat[i][house] + adjMat[house][j]);
                }
            }
        }

        vector<int> ans(n, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adjMat[i][j] != 0) {

                    int val = adjMat[i][j];
                    ans[val - 1]++;
                }
            }
        }

        return ans;
    }
};