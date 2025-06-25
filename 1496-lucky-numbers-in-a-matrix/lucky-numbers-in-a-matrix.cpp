class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        
        int colMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            int rowMin = INT_MAX;
            for (int j = 0; j < m; j++) {
                rowMin = min(rowMin, matrix[i][j]);
            }
            colMax = max(colMax, rowMin);
        }
        

        int colMaxMIN = INT_MAX;
        for (int j = 0; j < m; j++) {
            int rowMinMAX = INT_MIN;
            for (int i = 0; i < n; i++) {
                rowMinMAX = max(rowMinMAX, matrix[i][j]);
            }
            colMaxMIN = min(colMaxMIN, rowMinMAX);
        }
        
        if(colMax == colMaxMIN ) 
            return {colMax};

        return {};
    }
};

/*

3  7  8   10  => rowMin[ 3, 9, 15]
9  11 13  11  => colMax[15, 16, 17, 12]
15 16 17  12

*/