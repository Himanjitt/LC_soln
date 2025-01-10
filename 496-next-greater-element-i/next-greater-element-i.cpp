class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        int n=nums2.size();
        stack<int> s;
        vector<int> v(n,-1);

        for (int i =0;i<n;i++) {

            while (s.empty()==false && nums2[s.top()] < nums2[i]) {
                
                v[s.top()]=nums2[i];
                s.pop();     
            }
            s.push(i);
        }
        
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) {
                ans.push_back(v[mp[nums1[i]]]);
            }
        }

        return ans;
    }
};