class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.size();
        vector<int>diff(n,0);

        for(auto query: shifts){
            int L = query[0];
            int R = query[1];
            int x;

            if(query[2]==0){
                x=-1;
            }else{
                x=1;
            }

            diff[L]=diff[L]+x;
            if(R+1<n)
                diff[R+1]=diff[R+1]-x;
        }

        for(int i=1;i<n;i++){
            diff[i]=diff[i-1]+ diff[i];
        }

        for(int i=0;i<n;i++){
            int shift=diff[i]%26;

            if(shift<0){
                shift=shift+26;
            }
            s[i]='a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};