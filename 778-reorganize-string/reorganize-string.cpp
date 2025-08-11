class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        string res="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        
        for(char ch: S){
            mp[ch]++;
        }
            
        for(auto it: mp){
            if(it.second > (n+1)/2 ){
                return "";
            }
            pq.push({it.second,it.first});
        }
            
        
        while(pq.size() >= 2){ //atleast two chars must be there in the pq
            auto top1= pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res += top1.second;
            res += top2.second;
            
            top1.first -= 1;
            top2.first -= 1;
            
            if(top1.first > 0){
                pq.push(top1);
            }
                
            if(top2.first > 0){
                pq.push(top2);
            }
        }
        
        if(!pq.empty()){

            res += pq.top().second;
        }
        
        return res;
    }
};