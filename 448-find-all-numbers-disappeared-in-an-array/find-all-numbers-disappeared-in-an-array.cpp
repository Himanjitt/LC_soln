/*
 0  1  2  3  4  5  6  7
[4 ,3 ,2 ,7 ,8 ,2 ,3 ,1]

[-4 ,-3 ,-2 ,-7 ,8 ,2 ,-3 ,-1]

*/
class Solution {
public:
/*
using index to mark as -ve
*/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            int index = abs(nums[i]) - 1;

            nums[index] = -1 * abs(nums[index]) ;
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }

        return ans;

    }
};