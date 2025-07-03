// variation of next permutation
class Solution {
public:
    void nextPermutation(string &nums) {
        //find the breaking point
        int n = nums.size();
        int breakInd=-1;
        for(int i = n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                breakInd = i;
                break;
            }
        }
        if(breakInd == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(int i= n-1;i>=breakInd;i--){
            if(nums[breakInd] < nums[i]){
                swap(nums[breakInd], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + breakInd + 1, nums.end());
    }

    int nextGreaterElement(int n) {
        string s = to_string(n);
        nextPermutation(s);
        long long next = stoll(s);
        if(next <= n || next > INT_MAX){
            return -1;
        }

        return next;
    }
};
