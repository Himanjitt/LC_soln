class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> last_view;
        unordered_set<char> disqualified;
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                last_view[word[i]] = i;
            }
        }


        int count = 0;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                char lower_ch=tolower(word[i]);
                if(disqualified.count(lower_ch)>0){
                    continue;
                }
                if (last_view.count(lower_ch) > 0 && i>last_view[lower_ch]){
                    count++;          
                }
                disqualified.insert(lower_ch);
                
            }
        }

        return count;
    }
};