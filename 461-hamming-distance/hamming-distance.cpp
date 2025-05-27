class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int count1s = 0;
        
        for (int i = 0; i < 32; i++) {
            if ((ans >> i) & 1 == 1) {
                count1s += 1;
            }
        }
        return count1s;
    }
};