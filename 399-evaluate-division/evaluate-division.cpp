class Solution {
public:
    map<string,vector<pair<string, double>>> adj;

    void dfs(string node, string dest, unordered_set<string> visited, double product, double &ans){
        
        if(node == dest){
            ans = product;
            return;
        }
        visited.insert(node);

        for(auto neighbor: adj[node]){
            string v = neighbor.first;
            double wt= neighbor.second;

            if(visited.find(v) == visited.end()){
                dfs(v, dest, visited, product * wt, ans);
            }
        }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //equations are edges, values are weights
        //each query is a separate dfs call

        int n = equations.size();

        for(int i=0;i<n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];

            adj[u].push_back({v,wt});
            adj[v].push_back({u, 1.0 / wt});
        }

        vector<double> result;

        for(auto query: queries){
            string src = query[0];
            string dest = query[1];

            if(adj.find(src) == adj.end()){
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double ans = -1.0;
            double product = 1.0;
            dfs(src, dest, visited, product, ans);

            result.push_back(ans);
        } 

        return result;
    }
};