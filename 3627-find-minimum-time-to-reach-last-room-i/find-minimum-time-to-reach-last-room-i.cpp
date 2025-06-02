class Solution {
public:
    typedef pair<int, pair<int, int>> Node;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        if (n == 0) return -1;
        int m = moveTime[0].size();

        vector<vector<int>> dirs= { {-1,0}, {1,0}, {0,-1}, {0,1} };

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        minTime[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int dis = current.first;
            int i = current.second.first;
            int j = current.second.second;

            if (i == n-1 && j == m-1) {
                return dis;
            }
            //optimization
            if (dis > minTime[i][j]) {
                continue;
            }

            for (auto ele: dirs) {
                int ni = i + ele[0];
                int nj = j + ele[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int arrival_time = max(dis, moveTime[ni][nj]) + 1;
                    if (arrival_time < minTime[ni][nj]) {
                        minTime[ni][nj] = arrival_time;
                        pq.push({arrival_time, {ni, nj}});
                    }
                }
            }
        }

        return -1;
    }
};