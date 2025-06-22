class Solution {
public:
    pair<int, int> getTokens(string num) {
        stringstream ss(num);

        string realStr;
        getline(ss, realStr, '+');

        string imagStr;
        getline(ss, imagStr, 'i');

        pair<int, int> ans = {stoi(realStr), stoi(imagStr)};

        return ans;
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> p1 = getTokens(num1);
        pair<int, int> p2 = getTokens(num2);

        int realPart = p1.first * p2.first - p1.second * p2.second;
        int imagPart = p1.first * p2.second + p1.second * p2.first;

        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};