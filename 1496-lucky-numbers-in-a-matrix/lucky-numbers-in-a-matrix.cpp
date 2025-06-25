class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rowMin(n, INT_MAX), colMax(m, INT_MIN);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

    
        for(int i=0;i < n;i++){
            for(int j=0;j< m;j++){
                if( (matrix[i][j] == rowMin[i]) && (matrix[i][j] == colMax[j]) ){
                    ans.push_back(rowMin[i]);
                }
            }
        }

        return ans;
    }
};

/*

3  7  8   10  => rowMin[ 3, 9, 15]
9  11 13  11  => colMax[15, 16, 17, 12]
15 16 17  12

*/