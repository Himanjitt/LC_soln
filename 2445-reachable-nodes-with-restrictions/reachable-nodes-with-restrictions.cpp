class Solution {
public:
    map<int,vector<int>>adj;
    
    unordered_set<int> visited;

    void dfs(int node,int &reachable, unordered_set<int> &restrictd){
        
        if(restrictd.find(node) != restrictd.end()){
            return;
        }

        visited.insert(node);
        reachable++;

        for(int neighbor: adj[node]){
            if(visited.find(neighbor) == visited.end()){
                dfs(neighbor, reachable, restrictd);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        unordered_set<int> restrictd(restricted.begin(), restricted.end());
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int reachable = 0;
        dfs(0, reachable, restrictd);

        return reachable;
    }
};