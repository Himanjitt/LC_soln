class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        if(m==0) return 0;
        if(n==0) return 0;
       
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && (j==0 || board[i][j-1]=='.')
                    && (i==0 || board[i-1][j]=='.')){
                        count++;
                    }
            }
        }

        return count;
    }
};