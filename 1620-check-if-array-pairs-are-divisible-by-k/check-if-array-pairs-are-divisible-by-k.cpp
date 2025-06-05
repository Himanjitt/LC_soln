class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int rem=((arr[i] % k) + k) % k;
            mp[rem]++;
        }
        if(mp[0] % 2 !=0 ) return false;

        for(int i=1;i<=k/2;i++){
            int comple = k-i;
            if(mp[comple] != mp[i]){
                return false;
            }
        }

        return true;
    }
};