class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        //be greedy and put the larges
        // number first in the odd places
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }

        for(int i= 1;i<n;i=i+2){
            nums[i]= pq.top();
            pq.pop();
        }
        for(int i=0;i<n;i=i+2){
            nums[i] = pq.top();
            pq.pop();
        }

    }
};

/*
 0  1  2  3  4  5
[1 ,2 ,1 ,2 ,2 ,1]


 0  1  2  3  4  5 
[1, 5, 1, 6, 1, 4]

*/