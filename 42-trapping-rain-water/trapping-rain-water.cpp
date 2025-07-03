class Solution{
public:
    int trap(vector<int> &height){
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = 0, rightMax[n-1] = 0;

        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        // for(auto ele: leftMax){
        //     cout<< ele<<" ";
        // }
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        // for(auto ele: rightMax){
        //     cout<< ele<<" ";
        // }
        int ans =0;

        for(int i=0;i<n;i++){
            if(min(leftMax[i],rightMax[i]) - height[i]> 0){
                ans += min(leftMax[i],rightMax[i]) - height[i];
            }
            
        }
        return ans;;
    }
};

/*
total water = 0+1+1;

max to the left and max to the right
min(0,2) = 0  

min(1, 2) = 1 - 0 = 1
min(1,3) = 1 -2 = 
min(2,3) = 2 - 1 = 1
min(2, 3) = 2 -0 =2
*/