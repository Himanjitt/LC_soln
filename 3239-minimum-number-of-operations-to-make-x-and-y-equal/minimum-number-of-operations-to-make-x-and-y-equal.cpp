class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        
        if(x<=y){
            return y-x;
        }
        unordered_set<int>visited;

        queue<int>q;
        visited.insert(x);
        q.push(x);

        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();

                if(node==y){
                    return steps;
                }
                if(node -1 >=1 && visited.count(node-1)==0){
                    q.push(node-1);
                    visited.insert(node-1);
                }
                if(node+1<x+11 && visited.count(node+1)==0){
                    q.push(node+1);
                    visited.insert(node+1);
                }
                if(node%5==0 && visited.count(node/5)==0){
                    q.push(node/5);
                    visited.insert(node/5);
                }
                if(node%11==0 && visited.count(node/11)==0){
                    q.push(node/11);
                    visited.insert(node/11);
                }
            }
            steps++;
        }

        return steps;
    }
};