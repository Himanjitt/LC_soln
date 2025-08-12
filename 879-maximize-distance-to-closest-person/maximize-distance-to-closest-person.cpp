class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> nearestLeft(n, -1);
        vector<int> nearestRight(n, -1);

        // Fill nearestLeft
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1){
                last = i;
            } 

            if (last != -1){
                nearestLeft[i] = i - last;
            } 
        }

        // Fill nearestRight
        last = -1;
        for (int i = n - 1; i >= 0; i--) {

            if (seats[i] == 1) {
                last = i;
            }

            if (last != -1){
                nearestRight[i] = last - i;
            } 
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                int leftDist = (nearestLeft[i] == -1) ? INT_MAX : nearestLeft[i];
                int rightDist = (nearestRight[i] == -1) ? INT_MAX : nearestRight[i];
                ans = max(ans, min(leftDist, rightDist));
            }
        }
        return ans;
    }
};
