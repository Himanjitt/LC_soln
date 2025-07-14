/*

              i
["a","3","b","2","b","a","a"]
                      j
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j =0;

        while(j < n){
            int len=0;
            char currentChar = chars[j];
            while(j < n && chars[j] == currentChar){
                len++;
                j++;
            }
            chars[i] = currentChar;
            i++;

            if(len > 1){
                string lenstr= to_string(len);
                for(char ch : lenstr){
                    chars[i] = ch;
                    i++;
                }
            }
        }

        return i;
    }
};