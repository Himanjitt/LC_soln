class Solution {
public:
    static bool comparator(string a,string b){
        // "10" + "2" = "102"
        // "2" + "10" = "210"
        if(a + b > b + a){
            return true;
        }

        return false;
    }
    string largestNumber(vector<int>& nums) 
    {
        vector<string>strNum;
        for(int n:nums) {
            strNum.push_back(to_string(n));
        }
        sort(strNum.begin(), strNum.end(),comparator);
        
        if(strNum[0] == "0"){ //if even after sorting 0th is "0" then "0"
            return "0";
        }

        string ans;
        for(string s : strNum){
            ans += s;
        }
        return ans;
    }
};