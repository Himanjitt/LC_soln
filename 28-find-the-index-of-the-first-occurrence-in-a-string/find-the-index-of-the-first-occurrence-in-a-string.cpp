class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        for (i = 0; i < n; i++) {
            if (haystack[i] == needle[0]) {
                int hpointer = i;
                int npointer = 0;

                while(hpointer < n && npointer < m){
                    if(haystack[hpointer] != needle[npointer]){
                        break;
                    }
                    if(npointer == m-1){
                        return i;
                    }
                    hpointer++;
                    npointer++;
                }
            }
        }

        return -1;
    }
};