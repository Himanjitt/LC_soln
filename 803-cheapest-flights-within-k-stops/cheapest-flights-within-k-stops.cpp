class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        map<int, vector<pair<int, int>>> adj;

        for (auto edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, int>>q;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src, 0});

        int level = 0;
        while (!q.empty()) {
            int size = q.size();

            if (level > k) {
                break;
            }
            while (size--) {
                auto top = q.front();
                q.pop();
                
                int u = top.first;
                int u_wt = top.second;

                for (auto neighbor : adj[u]) {
                    int v = neighbor.first;
                    int wt = neighbor.second;

                    if (u_wt + wt < dist[v]) {
                        dist[v] = u_wt + wt;
                        q.push({v, dist[v]});
                    }
                }
            }
            level++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};