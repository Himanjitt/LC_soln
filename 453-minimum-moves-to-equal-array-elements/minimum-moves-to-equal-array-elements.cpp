class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int moves = 0;

        for(int i=0;i<nums.size();i++){
            moves += abs(nums[i]-mini);
        }
        return moves;
    }
};


/*

1 5 7 
2 6 7
3 7 7
4 8 7
5 8 8
6 9 8
7 9 9
8 10 9
9 10 10
10 11 10
11 11 11


 with reverse removing 1 from the largest
essentially will go to 1 1 1 
so 1(min) we have to make it equal to eveyone
1-5 = 4 , 1-7 =6 total 10 moves  

1 5 7 
1 5 6
1 5 5
1 4 5
1 4 4
1 3 4 
1 3 3 
1 2 3
1 2 2
1 1 2
1 1 1

*/