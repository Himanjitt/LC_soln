class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> last_lowercase_index; // Track the last index of each lowercase letter
        unordered_set<char> disqualified; // Track letters disqualified from being special
        int count = 0;

        // First pass: Record the last occurrence of each lowercase letter
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                last_lowercase_index[word[i]] = i;
            }
        }

        // Second pass: Check for uppercase letters and validate the condition
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                char lowercase_char = tolower(word[i]);

                // If this letter has already been disqualified, skip it
                if (disqualified.count(lowercase_char)) {
                    continue;
                }

                // Check if all lowercase occurrences appear before this uppercase letter
                if (last_lowercase_index.count(lowercase_char) > 0 &&
                    last_lowercase_index[lowercase_char] < i) {
                    count++; // Valid special character
                    disqualified.insert(lowercase_char); // Mark as processed
                } else {
                    disqualified.insert(lowercase_char); // Disqualify if condition fails
                }
            }
        }

        return count;
    }
};
