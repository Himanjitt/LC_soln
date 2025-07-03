//idea is to find the max in a particular row (row would be chose by BS)
//check its up and down is less or not and according eliminate the rows
class Solution {
public:
    int findInd(vector<int> nums){
        int maxi =nums[0];
        int maxInd = 0;

        for(int i =0;i<nums.size();i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxInd = i;
            }
        }

        return maxInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        int start = 0, end = r-1;

        
        while(start <= end){
            int mid = start+ (end - start)/2;

            int maxColInd = findInd(mat[mid]);
            
            int up = (mid - 1 < 0) ? -1 : mat[mid-1][maxColInd];
            int down = (mid + 1 >= r ) ? -1 : mat[mid+1][maxColInd];
            
            if(mat[mid][maxColInd] > up && mat[mid][maxColInd] > down){
                return {mid, maxColInd};
            }
            else if(mat[mid][maxColInd] < up){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }

        return {-1, -1};
    }
};