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
    int makeConnected(int n, vector<vector<int>>& Edge) {
        disjointSet ds(n);
        int extraEdges = 0;
        for (auto ele : Edge) {
            int u = ele[0];
            int v = ele[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {
                extraEdges++;
            } else {
                ds.unionBySize(u, v);
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.uParents[i] == i) {
                components++;
            }
        }
        int ans = components - 1;
        if (extraEdges >= ans) {
            return ans;
        }

        return -1;
    }
};