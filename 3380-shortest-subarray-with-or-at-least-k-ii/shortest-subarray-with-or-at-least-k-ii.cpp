class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        int cur=0, ans=n+1;
        //storing setbit cnt at each position 
        vector<int>bitcnt(32,0);

        while(i<=j && j<n){
            //adding nums[j] to cur
            cur|=nums[j];
            for(int bitno=0; bitno<32; bitno++){
                if(nums[j] & (1<<bitno)){
                    bitcnt[31-bitno]++;
                }
            }
            //check
            while(i<=j && cur>=k){
                //storing ans
                ans=min(ans, j-i+1);

                //removing nums[i] from cur
                for(int bitno=0; bitno<32; bitno++){
                    if(nums[i] & (1<<bitno)){
                        bitcnt[31-bitno]--;
                    }
                }

                //shrinking window size by increasing left pointer
                i++;

                //updated cur
                int newcur=0;
                for(int bitno=31; bitno>=0; bitno--){
                    if(bitcnt[bitno]){
                        newcur+=pow(2,31-bitno);
                    }
                }
                cur=newcur;
            }
            j++;    
        }
        if(ans==n+1) return -1;
        return ans;
    }
};