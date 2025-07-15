class Solution {
public:
    // normal bfs with maximum levels possible as K and relaxation
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
        queue<pair<int, int>> q;
        int levels = 0;

        q.push({src, 0});

        while (!q.empty()) {
            int size = q.size();

            if(levels > K){
                break;
            }
            while (size--) {
                auto node = q.front();
                q.pop();

                int u = node.first;
                int dis = node.second;

                for (auto neighbor : adj[u]) {
                    int v = neighbor.first;
                    int wt = neighbor.second;

                    if (wt + dis < distance[v]) {
                        distance[v] = wt + dis;
                        q.push({v, distance[v]});
                    }
                }
            }
            levels++;
        }

        if (distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};