class Solution {
public:
    //Full symmetric  (a2 >= b1 && b2 >= a1) is only necessary 
    //when the list is not sorted, or we're comparing arbitrary pairs.
    //ie .v[1]>=intervals[i][0] && intervals[i][1] > v[0]
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else {
                vector<int> &v = ans.back();
                /*
                Two intervals A = [a1, a2] and B = [b1, b2]
                overlap if and only if:
                a2 >= b1 && b2 >= a1
                here not necessary because already sorted
                */
                if(v[1]>=intervals[i][0]){
                    v[0]=min(v[0],intervals[i][0]);
                    v[1]=max(v[1],intervals[i][1]);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};