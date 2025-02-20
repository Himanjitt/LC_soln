class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {

        size_t star1 = p.find('*');
        size_t star2 = p.find('*', star1 + 1);

        string prefix = p.substr(0, star1);
        string middle = p.substr(star1 + 1, star2 - star1 - 1);
        string suffix = p.substr(star2 + 1);

        int len_prefix = prefix.length();
        int len_middle = middle.length();
        int len_suffix = suffix.length();

        if (len_prefix == 0 && len_middle == 0 && len_suffix == 0) {
            return 0;
        }

        vector<int> prefix_starts = find_all(s, prefix);
        vector<int> middle_starts;
        if (len_middle > 0) {
            middle_starts = find_all(s, middle);
        } else {

            middle_starts.reserve(s.length() + 1);
            for (int j = 0; j <= s.length(); ++j) {
                middle_starts.push_back(j);
            }
        }
        vector<int> suffix_starts;
        if (len_suffix > 0) {
            suffix_starts = find_all(s, suffix);
            sort(suffix_starts.begin(), suffix_starts.end());
        }

        sort(middle_starts.begin(), middle_starts.end());

        int min_length = INT_MAX;
        bool found = false;

        if (len_prefix > 0) {
            for (int i : prefix_starts) {

                auto it = lower_bound(middle_starts.begin(),
                                      middle_starts.end(), i + len_prefix);
                if (it != middle_starts.end()) {
                    int j = *it;
                    if (len_suffix > 0) {

                        auto it2 =
                            lower_bound(suffix_starts.begin(),
                                        suffix_starts.end(), j + len_middle);
                        if (it2 != suffix_starts.end()) {
                            int k = *it2;
                            if (k + len_suffix <= s.length()) {
                                int length = k + len_suffix - i;
                                min_length = min(min_length, length);
                                found = true;
                            }
                        }
                    } else {

                        int length = j + len_middle - i;
                        min_length = min(min_length, length);
                        found = true;
                    }
                }
            }
        } else {

            for (int j : middle_starts) {
                if (len_suffix > 0) {

                    auto it2 = lower_bound(suffix_starts.begin(),
                                           suffix_starts.end(), j + len_middle);
                    if (it2 != suffix_starts.end()) {
                        int k = *it2;
                        if (k + len_suffix <= s.length()) {
                            int length = k + len_suffix - j;
                            min_length = min(min_length, length);
                            found = true;
                        }
                    }
                } else {

                    int length = len_middle;
                    min_length = min(min_length, length);
                    found = true;
                }
            }
        }

        return found ? min_length : -1;
    }

private:
    vector<int> find_all(const string& s, const string& pattern) {
        vector<int> starts;
        if (pattern.empty()) {
            return starts;
        }
        size_t pos = 0;
        while ((pos = s.find(pattern, pos)) != string::npos) {
            starts.push_back(pos);
            pos += 1;
        }
        return starts;
    }
};