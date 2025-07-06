class Solution {
public:
    bool isValid(string& prefix, string& target) {
        int n = prefix.size();
        string s = target.substr(0, n);
        if (s == prefix) {
            return true;
        }
        return false;
    }
    void search(vector<string>& temp, vector<string>& products,
                string& prefix) {
        int start = 0, end = products.size() - 1;

        int idx = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            //lexicographically comparing
            if (products[mid] >= prefix) {
                idx = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if(idx == -1){
            return;
        }
        for (int i = idx ; i < products.size() && i < idx + 3; i++) {
            if(isValid(prefix,products[i]) == true){
                temp.push_back(products[i]);
            }
            else {
                break;
            }    
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        for (auto ele : products) {
            cout << ele << " ";
        }
        cout<< endl;
        vector<vector<string>> ans;
        string prefix = "";
        
        for (char ch : searchWord) {
            prefix += ch;
            vector<string> temp;
            search(temp, products, prefix);
            ans.push_back(temp);
        }
        
        return ans;
    }
};