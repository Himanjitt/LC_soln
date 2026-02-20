class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(), str.end());
			
			// for(string s: str){
			// 	cout<<s<<" ";
			// }
			
			string startWord = str[0];
			string endWord = str[str.size() - 1];

			string ans = "";

			int i =0, j = 0;

			while(i != startWord.size() && j != endWord.size()){
				if(startWord[i] != endWord[j]){
					return ans;
				}

				ans += startWord[i];
				i++;
				j++;
			}

			return ans;
    }
};