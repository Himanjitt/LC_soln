class Solution {
public:
    unordered_map<int,vector<int>>adj;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1){
            return {0};
        }
        vector<int> indeg(n,0);
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            
            indeg[u]++;
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int size=q.size();
            n=n-size;
            while(size>0){
                int curr=q.front();
                q.pop();

                for(auto neighbor: adj[curr]){
                    indeg[neighbor]--;

                    if(indeg[neighbor]==1){
                        q.push(neighbor);
                    }
                }
                size--;
            }        
        }
        vector<int>ans;
        while(q.empty()==false){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
        }

        return ans;
    }
};