/*

123 / 10 = 12
123 % 10 = 3

rem = 2
x = 1
ans = 3 * 10 + 2 = 32
*/

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        
        while(x!=0){
            int rem = x%10;
            x = x/10;
            if(ans > INT_MAX / 10 || (ans < INT_MIN / 10)) {
                return 0;
            }
            ans =ans * 10 + rem;
        }

        return ans;
    }
};