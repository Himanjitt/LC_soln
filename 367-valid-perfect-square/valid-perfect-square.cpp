class Solution {
public:
    bool isPerfectSquare(int num) {
        // search range is 1-num
        int start = 1, end = num;
        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};