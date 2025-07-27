class Solution {
public:
    void findNS(vector<int>& NS, vector<int>& heights) {
        stack<int> st1;
        for (int i = 0; i < heights.size(); i++) {
            while (st1.empty() == false && heights[i] < heights[st1.top()]) {
                NS[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
    }

    void findPS(vector<int>& PS, vector<int>& heights) {
        stack<int> st2;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (st2.empty() == false && heights[i] < heights[st2.top()]) {
                PS[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NS(n, n);
        vector<int> PS(n, -1);
        // vector<int> width(n);
        // vector<int> area(n);
        findNS(NS, heights);
        findPS(PS, heights);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = NS[i] - PS[i] - 1;
            int area = width * heights[i];
            maxi = max(maxi, area);
        }
        return maxi;
    }
};