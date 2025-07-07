class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> ans;

        while (i < firstList.size() && j < secondList.size()) {
            vector<int> &v1 = firstList[i];
            vector<int> &v2 = secondList[j];
             /*
                Two intervals A = [a1, a2] and B = [b1, b2]
                overlap if and only if:
                a2 >= b1 && b2 >= a1
            */
            if (v1[1] >= v2[0] && v1[0] <= v2[1]) { // there is overlap
                ans.push_back({max(v1[0], v2[0]), min(v1[1], v2[1])});
                //now move the pointer of the one which is shorter
                //handled below
            }

            if (v1[1] < v2[1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

/*
                            i
                    -------------------
                    4                  11
                     j
----            --------        -------------
1   2           8       9       12         13


*/