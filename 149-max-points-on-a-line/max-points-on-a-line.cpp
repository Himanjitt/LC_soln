class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        int m = points.size();
        for(int i =0;i<m-1;i++){
            unordered_map<double, int> mp;
            double slope =0;
            for(int j=i+1;j<m;j++){
                vector<int> &p1 = points[i];
                vector<int> &p2 = points[j];
                slope = (p2[0] -p1[0] == 0) ? INT_MAX : (double)(p2[1] - p1[1]) / (p2[0] -p1[0]);
                mp[slope]++;
            }

            for(auto it: mp){
                ans = max(ans, it.second);
            }
        }

        return ans+1;
    }
};