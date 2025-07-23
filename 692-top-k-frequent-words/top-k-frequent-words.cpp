/*

i -> 2
love -> 2
leetcode -> 1
coding -> 1

i -> {2, i}
love -> {2, love}


*/

class Solution {
public:
    struct compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                if (a.second < b.second) { // reverse logic for pq , min heap (optimized)
                    return true;
                }
                return false;
            }

            if (a.first > b.first) {// reverse logic for pq , min heap (optimized)
                return true;
            }

            return false;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, compare>
            pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end()); //reverse for min heap
        return ans; //  O(ulogk)
    }
};