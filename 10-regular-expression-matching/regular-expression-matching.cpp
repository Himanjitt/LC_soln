class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        if(j == p.size()){
            //both should end at same time
            if(i == s.size()){
                return true;
            }
            return false;
        }

        if(p[j+1] == '*'){
            //not take
            bool notTake = solve(s, p, i, j+2);
            //take
            bool take = false;
            if((i < s.size()) && (s[i] == p[j] || p[j] == '.')){
                take = solve(s, p, i+1, j);
            }

            return notTake || take;
        }

        //else means normal case
        bool elseOP = false;
        if((i < s.size()) && (s[i] == p[j] || p[j] == '.')){
            elseOP = solve(s, p, i+1, j+1);
        }
        return elseOP;
    }


    bool isMatch(string s, string p) {
        
        return solve(s, p, 0, 0);
    }
};