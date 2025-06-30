// Agressive Cows variation
class Solution {
public:
    bool isValid(int mid, vector<int>& position, int m) {
        int count = 1;
        int lastpos = 0;
        for (int i = 1; i < position.size(); i++) {
            if (abs(position[i] - position[lastpos]) >= mid) {
                count++;
                lastpos = i;
            }
        }

        if (count >= m) {
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        // search space 1 to max(nums) - min(nums)
        int n = position.size();
        sort(position.begin(), position.end());
        int start = 1, end = position[n - 1] - position[0];
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(mid, position, m) == true) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};