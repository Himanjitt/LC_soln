class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            for(int j=0;j<prerequisites[0].size();j++){
                int u=prerequisites[i][1];
                int v=prerequisites[i][0];
                adj[u].push_back(v);
                
            }
        }
        vector<int>indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto neighbor : adj[i]){
                indeg[neighbor]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto neighbor: adj[node]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(ans.size()!=numCourses){
            return false;
        }
        else return true;
        

    }
};