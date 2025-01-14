class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int count=0;

        vector<int> ans(A.size());
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                count++;
            }

            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;
            }

            ans[i]=count;
        }

        return ans;
    }
};