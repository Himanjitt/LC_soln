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

        for(auto it: adj){
            for(int num : it.second){
                indeg[num]++;
            }
        }
        
        queue<int>q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(q.empty()==false){
            int curr=q.front();
            q.pop();
            
            for(auto neighbor: adj[curr]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){
                    ans.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }
    
        sort(ans.begin(),ans.end());
        return ans;
    }
};