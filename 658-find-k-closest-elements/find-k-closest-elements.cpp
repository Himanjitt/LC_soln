/*
[1,2,3,4,5], k = 4, x = 3

3, 2 , 4, 1
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            if (pq.size() != k) {
                pq.push(arr[i]);
            } 
            else {
                if (abs(arr[i] - x) < abs(pq.top() - x)) {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }

        while (pq.size()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};