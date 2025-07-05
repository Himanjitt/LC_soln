class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<n;i++){
            //removing incase there are elements outside window
            while(dq.empty() == false && dq.front() <= i-k){
                dq.pop_front();
            }

            //before inserting ensuring monotonic decreasing property
            while(dq.empty() ==false && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            //inserting new element
            dq.push_back(i);

            //if windows size is reached we can get answer from front
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};