//check notes
class Solution {
public:
    static bool func(string &word1, string &word2){
        return word1.size() < word2.size();
    }

    bool isPredecessor(string &currWord, string &prevWord){
        if(currWord.size() - prevWord.size() != 1){
            return false;
        }
        //isSubsequece leetcode 392
        int iC=0, jP=0;

        while(iC < currWord.size()){
            if(prevWord[jP] ==  currWord[iC]){
                jP++;
                iC++;
            }else{
                iC++;
            }
        }
        if(jP == prevWord.size()) {
            return true;
        }
        return false;
    }
    int solve(vector<string>& words, int ind, int prevInd, vector<vector<int>>&dp){
        //pruning

        //base case
        if(ind == words.size()){
            return 0;
        }

        if(dp[ind][prevInd + 1] != -1){
            return dp[ind][prevInd + 1];
        }
        //not take
        int notTake = solve(words, ind+1, prevInd,dp);

        //take
        int take=0;
        if(prevInd == -1 || isPredecessor(words[ind], words[prevInd]) == true){
            take= 1 + solve(words, ind+1, ind, dp);
        }

        return dp[ind][prevInd + 1] = max(notTake, take);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        //custom sorting based on length
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(words.begin(),words.end(), func);
        return solve(words, 0, -1, dp);
    }
};