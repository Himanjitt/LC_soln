class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // position to write compressed output
        int read = 0;  // position to read through chars

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count occurrences of currentChar
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write] = currentChar;
            write++;

            // If count > 1, write digits of the count
            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[write] = ch;
                    write++;
                }
            }
        }

        return write;
    }
};
