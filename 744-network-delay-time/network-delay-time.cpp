class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto ele : times) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];
            adj[u].push_back({v, wt});
        }

        // Priority queue for Dijkstra's algorithm (min-heap based on time)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        //{time/dis,source}
        pq.push({0, k});

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int dis = node.first;
            int u = node.second;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (dis + wt < distance[v]) {
                    distance[v] = dis + wt;
                    pq.push({distance[v], v});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX)
                return -1;
            ans = max(ans, distance[i]);
        }

        return ans;
    }
};