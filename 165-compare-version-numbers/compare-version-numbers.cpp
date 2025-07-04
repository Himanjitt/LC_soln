class Solution {
public:
    vector<string> getTokens(string version){
        stringstream ss(version);
        string token;

        vector<string>ans;
        while(getline(ss, token, '.')){
            ans.push_back(token);
        }

        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int n1 = v1.size(), n2=v2.size();

        int i=0;
        while(i < n1 || i < n2){
            
            int a = (i < n1) ? stoi(v1[i]) : 0;
            int b = (i < n2) ? stoi(v2[i]) : 0;

            if(a > b){
                return 1;
            }
            else if( a < b){
                return -1;
            }

            i++;
        }

        return 0;

    }
};