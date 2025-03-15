class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); i++) {
            arr1.push_back(arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        int n = arr1.size();
        if (n % 2 == 1) {
            return arr1[n / 2];
        } else {
            double sum = 0;
            sum = arr1[n / 2] + arr1[n / 2 - 1];
            return sum / 2;
        }

        return -1;
    }
}

;