class Solution {
public:
    vector<int> partitionLabels(string s) {
        //map for last index;
        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }

        vector<int> output;
        int end = -1;
        int size = 0;

        for(int i=0;i<s.size();i++){
            end = max(end, mp[s[i]]);
            size++;

            if(i == end){
                output.push_back(size);
                size = 0;     
            }
        }
        return output;
    }
};