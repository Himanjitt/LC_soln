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
                if (a.second > b.second) { // reverse logic for pq , max heap
                    return true;
                }
                return false;
            }

            if (a.first < b.first) {
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
        }

        vector<string> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};