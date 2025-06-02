class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int K) {
        map<int, vector<pair<int, int>>> adj;
        for (auto ele : flights) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            adj[u].push_back({v, wt});
        }
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        int stops = 0;
        pq.push({stops, {src, 0}});
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int stops = node.first;
            int u = node.second.first;
            int dis = node.second.second;

            if (stops > K)
                continue;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int wt = neighbor.second;

                if (wt + dis < distance[v]) {
                    distance[v] = wt + dis;
                    pq.push({stops + 1, {v, distance[v]}});
                }
            }
        }

        if (distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};