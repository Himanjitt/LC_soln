class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // KAHN algo

        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();

        map<string, vector<int>> adj;
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; i++) {
            for (string ing : ingredients[i]) {
                if (st.count(ing) == 0) {
                    adj[ing].push_back(i);
                    indeg[i]++;
                }
            }
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<string> ans;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            string food = recipes[front];
            ans.push_back(food);

            for(int neighbor : adj[food]){
                indeg[neighbor]--;
                if(indeg[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};