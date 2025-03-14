class Solution {
public:
    bool isPerfectSquare(int num) {
        //search range is 1-num
        for(long long i=1;i<=num;i++){
            if(i*i==num){
                return true;
            }
        }

        return false;
    }
};