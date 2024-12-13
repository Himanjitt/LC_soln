class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
            ){
            return true;
        }
        return false;
    }
    string reverseVowels(string word) {
        int start=0;
        int end=word.size()-1;
        while(start<=end){
            if(isVowel(word[start]) && isVowel(word[end])){
                swap(word[start], word[end]);
            }
            else if(isVowel(word[start])){
                end--;
                continue;
            }else if(isVowel(word[end])){
                start++;
                continue;
            }
            start++;
            end--;
        }
        return word;
    }
};