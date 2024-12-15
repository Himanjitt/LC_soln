class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> leftPenal(n+1);  // Penalties for "N" up to index i
        vector<int> rightPenal(n+1); // Penalties for "Y" after index i
        
        // Calculate leftPenal
        leftPenal[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'N') {
                leftPenal[i] = leftPenal[i - 1] + 1;
            } else {
                leftPenal[i] = leftPenal[i - 1];
            }
        }
        
        // Calculate rightPenal
        rightPenal[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                rightPenal[i] = rightPenal[i + 1] + 1;
            } else {
                rightPenal[i] = rightPenal[i + 1];
            }
        }
        
        // Find the minimum penalty and corresponding hour
        int minHour = 0;
        int minPenal = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int totalPenalty = leftPenal[i] + rightPenal[i];
            if (totalPenalty < minPenal) {
                minPenal = totalPenalty;
                minHour = i;
            }
        }

        return minHour;
    }
};
