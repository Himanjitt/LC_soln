class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count = 0;
        int maxCount = 0;
        for (int bitPos = 0; bitPos < 32; bitPos++) {
            for (int i = 0; i < candidates.size(); i++) {
                if ((candidates[i] & (1 << bitPos)) !=0) {
                    count++;
                }
            }
            maxCount = max(maxCount, count);
            count=0;
        }
        return maxCount;
    }
};