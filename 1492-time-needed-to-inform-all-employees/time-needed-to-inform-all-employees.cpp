class Solution {
public:
    map<int, vector<int>> adj;
    void dfs(int node, vector<int>& informTime, int& maxTime,
             unordered_set<int>& visited, int currTime) {

        visited.insert(node);

        currTime = currTime + informTime[node];
        maxTime = max(maxTime, currTime);

        for (int neighbor : adj[node]) {
            if (visited.count(neighbor) == 0) {
                dfs(neighbor, informTime, maxTime, visited, currTime);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {

        for (int i = 0; i < manager.size(); i++) {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }

        int maxTime = 0;
        unordered_set<int> visited;
        dfs(headID, informTime, maxTime, visited, 0);
        return maxTime;
    }
};