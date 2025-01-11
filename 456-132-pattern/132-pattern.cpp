class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        int nums3=INT_MIN;
        stack<int>st;

        // here we did reverse traversal because we meed to take care of the 
        // largest index
        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums3){
                return true;
            }
            while(st.empty()==false && st.top() < nums[i]){
                nums3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};