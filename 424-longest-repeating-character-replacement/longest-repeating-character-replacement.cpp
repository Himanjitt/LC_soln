class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int n=s.size();
        int ans=0;
        vector<int>hash(26,0);
        int maxFreq=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxFreq=max(maxFreq,hash[s[right]-'A']);
            int changes=(right-left+1) - maxFreq;
            if(changes>k){
                hash[s[left]-'A']--;
                left++;
            }

            ans=max(ans,right-left+1);
            right++;
        }

        return ans;
      
       
    }
};