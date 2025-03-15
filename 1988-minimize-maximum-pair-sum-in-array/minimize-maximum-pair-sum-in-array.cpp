class Solution {
public:
    bool isSafe(vector<int>& nums,int m,int n){
        int temp=0;
        int x = 0 , y = n-1;
        while(x<y){
            if(nums[x]+nums[y] > m) return false;
            x++;
            y--;
        }
        return true;
    }
    
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = nums[0]+nums[1]; // Minimum possible value of pair sum
        int n = nums.size();
        int r = nums[n-1]+nums[n-2]; // // Maximum possible value of pair sum
        int res = r;
        while(l<=r){
            int m = l + (r-l)/2; // To avoid over flow
            if(isSafe(nums,m,n)){ // if mid is safe then all elements from [mid.....r] are also safe
                res = min(res,m);
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return res;
    }
};