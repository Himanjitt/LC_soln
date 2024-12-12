class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int c=capacity;
        int n=plants.size();
        int totalSteps=0;
        for(int i=0;i<n;i++){
            if(capacity>=plants[i]){
                totalSteps++;
                capacity-=plants[i];
            }else{
                totalSteps+=2*(i)+1;
                capacity=c;
                capacity-=plants[i];
            }
        }
        return totalSteps;
    }
};