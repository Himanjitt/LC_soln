/* 
it is sure that every integer occurs and at most twice
therefor by pigeon hole eveyone will be visited

 0  1  2  3  4  5  6  7
[4, 3, 2, 7, 8, 2, 3, 1]   => [1,n] => index from [0,n-1]
-4,-3,-2,-7      ,-3,-1

here 2 is pointing at index 1 2times therefore it will be +ve
the second time we find value at index 1 to be -ve hence 2 occured 2 times

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int ele : nums){
            //if already -ve , we have visited 2nd time
            if(nums[abs(ele) - 1] < 0) {
                ans.push_back(abs(ele));
            } 
            nums[abs(ele) - 1] = (-1) * nums[abs(ele)-1];
        }

        return ans;
    }
};