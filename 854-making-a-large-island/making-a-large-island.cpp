class disjointSet {
   public:
    vector<int> size;
    vector<int> uParents;

    disjointSet(int n) {
        size.resize(n, 1);
        uParents.resize(n);
        for (int i = 0; i < n; i++) {
            uParents[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == uParents[node]) {
            return node;
        }

        return uParents[node] = findUPar(uParents[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            uParents[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            uParents[ulp_v] = ulp_u;
        }
    }
};
class Solution {
   public:
    int n;
    bool isValid(int new_i, int new_j) {
        if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) {
            return false;
        }
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        // step 1 make the components
        n = grid.size();
        disjointSet ds(n * n);

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto dir : dirs) {
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if (isValid(new_i, new_j) && grid[new_i][new_j] == 1) {
                            int oldNode = i * n + j;
                            int newNode = new_i * n + new_j;

                            ds.unionBySize(oldNode, newNode);
                        }
                    }
                }
            }
        }

        // step2
        // find size of each by searching for 0s
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> components;
                    for (auto dir : dirs) {
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if (isValid(new_i, new_j) && grid[new_i][new_j] == 1) {
                            int newNode = new_i * n + new_j;

                            components.insert(ds.findUPar(newNode));
                        }
                    }
                    int size = 0;
                    for (auto it : components) {
                        size += ds.size[it];
                    }
                    //add the converted 0 size
                    size = size + 1;
                    maxi = max(maxi, size);
                }
            }
        }

        // Edge case
       //if all are 1 then all parent will be same
        return max(maxi, ds.size[ds.findUPar(0)]);
       
    }
};
