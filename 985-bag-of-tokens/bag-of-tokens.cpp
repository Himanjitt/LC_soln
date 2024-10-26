class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int left=0,right=n-1;
        int maxScore=0,score=0;
        while(left<=right){
            if(tokens[left]<=power){
                power-=tokens[left];
                score++;
                maxScore=max(maxScore,score);
                left++;
            }else if(score>0){
                power+=tokens[right];
                score--;
                right--;
            }else{
                break;
            }
        }
        return maxScore;
    }
};