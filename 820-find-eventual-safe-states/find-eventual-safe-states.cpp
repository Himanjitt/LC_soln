// reverse Kahn algo

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int u=i;
                int v=graph[i][j];

                adj[v].push_back(u);
            }
        }
        int n=graph.size();

        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            for(int j: adj[i]){
                indeg[j]++;
            }
        }
        queue<int>q;
        vector<int> track(n,false);

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                track[i]=true;
            }
        }

        while(q.empty()==false){
            int curr=q.front();
            q.pop();
            
            for(auto neighbor: adj[curr]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){
                    track[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(track[i]==true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};