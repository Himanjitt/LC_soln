class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> oddSorted;
        vector<int> evenSorted;

        for(int i=0;i<n;i++){
            if(i%2==0){
                evenSorted.push_back(nums[i]);
            }else{
                oddSorted.push_back(nums[i]);
            }
        }
        sort(oddSorted.begin(),oddSorted.end(),greater<int>());
        sort(evenSorted.begin(),evenSorted.end());
        
        for(auto i:oddSorted){
            cout<<i<<" ";
        }
        cout<<'\n';
          for(auto i:evenSorted){
            cout<<i<<" ";
        }
        int evenIndex=0,oddIndex=0;

        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=evenSorted[evenIndex];
                evenIndex++;
            }
            else{
                ans[i]=oddSorted[oddIndex];
                oddIndex++;
            }
        }
        return ans;

    }
};