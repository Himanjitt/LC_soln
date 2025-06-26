class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[n-1];
        vector<int> arr1(n);
        for(int i=n-2;i>=0;i--){
            maxi = max(maxi, arr[i+1]);
            arr1[i] = maxi;     
        }
        arr1[n-1] = -1;
        return arr1;
    }
};