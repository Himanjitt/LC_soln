class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows=numRows+1;
        vector<vector<int>>ans(numRows);

        for(int i=0;i<numRows;i++){    

            ans[i]=vector<int>(i+1,1);

            for(int j=1;j<=i-1;j++){
                ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
            }
        }

        return ans[numRows-1];
    
    }
};