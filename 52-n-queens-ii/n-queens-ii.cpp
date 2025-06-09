// see notes
class Solution {
public:
    bool check(int row, int col,vector<int>&queen){
        for(int i=0;i<row;i++){
            int prevQCol = queen[i];
            int prevQRow = i;
            //line check or diagonal check
            if(prevQCol == col || abs(row - prevQRow) == abs(col - prevQCol)){
                return false;
            }
        }

        return true;
    }
    int solve(int level,int n, vector<int>&queen){
        //pruning

        //base case
        if(level == n){
            return 1;
        }

        //choices at each level
        int ans=0;
        for(int col = 0;col<n;col++){
            if(check(level, col, queen)){
                queen[level]=col;
                int ways = solve(level+1,n,queen);
                ans+=ways;
                queen[level]=-1;
            }
        }

        return ans;
    }

    int totalNQueens(int n) {
        vector<int>queen(n,-1);
        return solve(0,n, queen);
    }
};