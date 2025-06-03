class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        map<int, vector<pair<int, long>>> adj;
        for (auto ele : roads) {
            int u = ele[0];
            int v = ele[1];
            long long wt = ele[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            long long dis = node.first;
            int u = node.second;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                long long wt = neighbor.second;

                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                } else if (dis + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        if (ways[n - 1] == 0)
            return -1;
        return (ways[n - 1]) % mod;
    }
};