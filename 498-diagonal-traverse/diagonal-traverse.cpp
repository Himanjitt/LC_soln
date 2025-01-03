class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int>ans;
        for(auto &it: mp){
            if(it.first % 2!=0){
                for(auto num: it.second)
                    ans.push_back(num);
            }else{
                reverse(it.second.begin(),it.second.end());
                for(auto num: it.second)
                    ans.push_back(num);
            }
        }


        return ans;
    }
};