class Solution {
   public:
    void solve(vector<vector<char> >& board, int i, int j, string word, int ind,
               bool& flag) {
        if(ind==word.size()){
            flag=true;
            return;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ){
            return;
        }
        if(board[i][j]!=word[ind]){
            return;
        }
        char temp=board[i][j];
        board[i][j]='#';

        solve(board, i+1, j, word, ind+1, flag);
        solve(board, i-1, j, word, ind+1, flag);
        solve(board, i, j+1, word, ind+1, flag);
        solve(board, i, j-1, word, ind+1, flag);

        board[i][j]=temp;
        
        }
    bool exist(vector<vector<char> >& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool flag = false;
                if (board[i][j] == word[0]) {
                    solve(board, i, j, word, 0, flag);
                }
                if (flag == true) {
                    return true;
                }
            }
        }
        return false;
    }
};