class Solution {
public:
    int pivotInteger(int n) {
        int leftvalue=1,rightvalue=n;
        int leftSum=leftvalue,rightSum=rightvalue;
        if(n==1) return 1;

        while(leftvalue<rightvalue){

            if(leftSum<rightSum){
                leftvalue++;
                leftSum+=leftvalue;
            }else{
                rightvalue--;
                rightSum+=rightvalue;
            }
            if(leftSum==rightSum && leftvalue+1==rightvalue-1){
                return leftvalue+1;
            }
        }
        return -1;
    }
};