//Moore's Voting Algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = -1;
        int n =nums.size();
        for(int i = 0;i<n;i++){
            if(count == 0){
                ele= nums[i];
                count = 1;
            }
            else if(nums[i] == ele){
                count ++;
            }
            else {
                count--;
            }
            
        }

        int totalCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == ele){
                totalCount ++;
            }
        }

        if(totalCount > (n/2)){
            return ele;
        }
        return -1;
    }
};