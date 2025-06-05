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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;
        disjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    ds.unionBySize(mp[accounts[i][j]], i);
                }
            }
        }
        vector<vector<string>> merged(n);

        for (auto it : mp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);

            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].size() == 0) {
                continue;
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(merged[i].begin(), merged[i].end());
            for (int j = 0; j < merged[i].size(); j++) {
                temp.push_back(merged[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};