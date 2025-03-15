class Solution {
public:
    bool isValid(vector<int>& a, int k, int i) {

        int pages = 0;
        int student = 1;

        for (int j = 0; j < a.size(); j++) {
            if (pages + a[j] <= i) {
                pages += a[j];
            } else {
                student++;
                pages = a[j];
            }
        }
        if (student <= k) {
            return true;
        }

        return false;
    }
    int splitArray(vector<int>& a, int k) {
        int start = *max_element(a.begin(), a.end());
        int end = accumulate(a.begin(), a.end(), 0);
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(a, k, mid) == true) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};