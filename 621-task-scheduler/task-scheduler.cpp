class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;

        for(char ch: tasks){
            mp[ch]++;
        }

        priority_queue<int, vector<int>> pq;

        for(auto it: mp){
            pq.push(it.second);
        }

        int time = 0;
        while(pq.empty() == false){
            
            vector<int>temp;
            //we can take n+1 tasks at once if available
            for(int i=1;i<=n+1;i++){

                if(pq.empty() == false){
                    int top = pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
            }

            for(int freq : temp){
                if(freq > 0){
                    pq.push(freq);
                }
            }

            if(pq.empty() == true){
                time += temp.size(); //last inclusion
            }else{
                time += n+1; //each time n+1 time;
            }
        }

        return time;
    }
};