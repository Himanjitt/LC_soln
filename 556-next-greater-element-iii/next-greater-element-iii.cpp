class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        long long next = stoll(s);
        if(next <= n || next > INT_MAX){
            return -1;
        }

        return next;
    }
};
