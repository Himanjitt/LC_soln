
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size() - 1;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> visited(n + 1, 0);
        visited[start] = 1;
        int mx = 0;
        while (!q.empty()) {
            auto node = q.front();
            int i = node.first;
            int level = node.second;
            mx = max(mx, level);
            q.pop();
            for (auto j : adj[i]) {
                if (visited[j] == 0) {
                    q.push({j, level + 1});
                    visited[j] = 1;
                }
            }
        }
        return mx + 1;
    }

    bool dfs(int u, int fl, vector<int>& vis, vector<vector<int>>& adj) {
        vis[u] = fl;
        for (auto v : adj[u]) {
            if (vis[v] == -1) {
                if (dfs(v, 1 - fl, vis, adj) == false)
                    return false;
            } else if (vis[v] == fl) {
                return false;
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // making adjenceny list
        vector<vector<int>> adj(n + 1);
        DisjointSet ds(n);
        for (auto i : edges) {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            ds.unionBySize(a, b);
        }
        // detecting for the odd length cycles
        vector<int> vis(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            // Check each component of the graph
            if (vis[i] == -1) {
                if (dfs(i, 0, vis, adj) == false)
                    return -1;
            }
        }
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int start = i;
            ans[i] = bfs(start, adj);
        }
        vector<int> ass(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ass[ds.findUPar(i)] = max(ass[ds.findUPar(i)], ans[i]);
        }
        int sum = 0;
        for (int i : ass)
            sum += i;
        return sum;
    }
};