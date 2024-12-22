class Solution {
public:
    //the trick is to count the number of edges outwards from 0
    //assume the graph to be undirected 
    //dfs from 0,count the number of edges outwards from 0

    unordered_map<int,vector<int>>adj;
    unordered_map<int,vector<int>>actual;

    void dfs(int i, vector<bool> &visited, int &count){
        if(visited[i]==1){
            return;
        }

        visited[i]=1;
        
        for(auto neighbor: adj[i]){

            if(visited[neighbor]==0){
                auto it=find(actual[i].begin(),actual[i].end(),neighbor);

                if(it!=actual[i].end()){
                    count++;
                }
                dfs(neighbor, visited, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        for(auto edge: connections){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            actual[u].push_back(v);
        }

        vector<bool>visited(n,0);
        
        int count=0;
        dfs(0, visited, count);

        return count;
    }
};