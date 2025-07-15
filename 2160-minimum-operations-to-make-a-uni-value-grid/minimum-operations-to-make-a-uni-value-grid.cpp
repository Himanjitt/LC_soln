class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());
        int n = nums.size();

        int median = nums[n / 2];
        cout<< median;
        int moves=0;

        for(int i=0;i<n;i++){
            if(abs(median - nums[i]) % x != 0){
                return -1;
            }
            moves += (abs(median - nums[i])) / x;
        }

        return moves;

    }
};

/*

2 4 6 8
1 2 3 5


1 2 3 4 
1+ 0 + 0

*/