/*

[1,2,3]

carry = 1

8 7 9

9 7 8
0 8 8

9 9 9
0 0 0


*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if(digits[n-1] + 1 <= 9){
            digits[n-1] = digits[n-1] + 1;
            return digits;
        }

        reverse(digits.begin(), digits.end());

        
        vector<int> ans;
        ans.push_back(0);
        int carry = 1;

        for(int i=1;i<n;i++){
            if(digits[i] + carry == 10){
                ans.push_back(0);
                carry = 1;
            }
            else{
                ans.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        if(carry){
            ans.push_back(1);
        }

        reverse(ans.begin(), ans.end());
        return ans;


    }
};