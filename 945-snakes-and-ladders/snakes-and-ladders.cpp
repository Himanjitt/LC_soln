class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
          // Function to convert cell number to board coordinates
        auto cordinates = [&](int num) -> pair<int, int> {
            int r = (num - 1) / n;       // Row number (0-indexed)
            int c = (num - 1) % n;       // Column number (0-indexed)
            if (r % 2 == 1) {
                c = n - 1 - c;           // Reverse column for odd rows
            }
            r = n - 1 - r;               // Reverse row order
            return {r, c};
        };
        queue<int>q;
        q.push(1);
        
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        visited[n-1][0]=1;
        
        int steps=0;
        while(q.empty()==false){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();

                if(node==n*n){
                    return steps;
                }
                for(int i=1;i<=6;i++){

                    int num=node+i;
                    if(num> n*n) break;
                    pair<int,int> cord=cordinates(num);
                    int r=cord.first;
                    int c=cord.second;
                    if(visited[r][c]==1){
                        continue;
                    }
                    visited[r][c]=1;
                    if(board[r][c]!=-1){
                        q.push(board[r][c]);
                    }
                    else{
                        q.push(num);
                    }
                }
                
            }
            steps++;
        }
        return -1;
    }
};