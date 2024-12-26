class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            vector<int> distance(n,INT_MAX);
            vector<int> par(n,-1);
            distance[i] = 0;
            queue<int> que;
            que.push(i);
            while (que.size())
            {
                int v = que.front();
                que.pop();
                for (auto it : adj[v])
                {
                    if (distance[it] == INT_MAX)
                    {
                        distance[it] = 1 + distance[v];
                        par[it] = v;
                        que.push(it);
                    }
                    else if(par[v] != it)
                        ans = min(ans, distance[v] + distance[it] + 1);
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};