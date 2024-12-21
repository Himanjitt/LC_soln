class Solution {
public:
    unordered_map<int, vector<int>> adjList;

    void dfs(int i, vector<int>& visited,int &nodes, int &edges) {

        if (visited[i] == 1) {
            return;
        }

        visited[i] = 1;
         nodes++;
         edges+=adjList[i].size();
        for (auto neighbor : adjList[i]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, visited,nodes,edges);
            }
        }
    }

    int countCompleteComponents(int V, vector<vector<int>>& edges) {

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(V, 0);

        int ans=0;
        int errors=0;
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                ans++;
                int nodes=0;
                int edges=0;

                dfs(i, visited,nodes,edges);
                
                if(edges!=(nodes*(nodes-1))) errors++;
            }
        }

        return ans-errors;
    }
};