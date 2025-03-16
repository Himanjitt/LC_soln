class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {

        int n1 = arr1.size(), n2 = arr2.size();
        int i = 0, j = 0;
        vector<int> arr3;
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                arr3.push_back(arr1[i]);
                i++;
            } else {
                arr3.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n1) {
            arr3.push_back(arr1[i]);
            i++;
        }
        while (j < n2) {
            arr3.push_back(arr2[j]);
            j++;
        }
        int n = arr3.size();
        if (n % 2 == 1) {
            return arr3[n / 2];
        } else {
            double sum = 0;
            sum = arr3[n / 2] + arr3[n / 2 - 1];
            return sum / 2;
        }

        return -1;
    }
}

;