class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int h=n-mid;
            if(citations[mid]>=h){
                ans=h;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};