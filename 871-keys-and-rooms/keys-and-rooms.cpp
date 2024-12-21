class Solution {
public:
    unordered_map<int, vector<int>> adjlist;

    void dfs(vector<bool>& visited, int i) {
        if (visited[i] == 1) {
            return;
        }
        visited[i] = 1;

        for (auto neighbor : adjlist[i]) {
            dfs(visited, neighbor);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adjlist[i].push_back(rooms[i][j]);
            }
        }

        vector<bool> visited(rooms.size(), 0);

        dfs(visited, 0);

        for (int i = 0; i < rooms.size(); i++) {
            if (visited[i] == 0) {
                return false;
            }
        }

        return true;
    }
};