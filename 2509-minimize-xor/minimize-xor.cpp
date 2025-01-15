class Solution {
public:
    int count(int num2){
        int countSet=0;
        int i=0;
        while(num2!=0){
            if((num2 & 1)==1){
                countSet++;
            }
            num2=num2>>1;
        }
        return countSet;
    }
    int minimizeXor(int num1, int num2) {
        
        int countnum2=count(num2);

        int ans=0;
        for(int i=31;i>=0 && countnum2 > 0;i--){
            if(num1 & (1<<i)){
                countnum2--;
                ans+=(1<<i);
            }
        }

        for(int i=0;i<32 && countnum2>0;i++){
            if((num1 & (1<<i)) == 0){
                countnum2--;
                ans+=(1<<i);
            }
        }

        return ans;

    }
};