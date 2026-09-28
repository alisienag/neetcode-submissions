class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> char_freq;
        std::unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int satisfied = 0;

        int min_l = INT_MAX;
        int min_len = INT_MAX;
        int l = 0;
        int r = 0;
        char_freq[s[0]]++;
        if (need.contains(s[0]) && char_freq[s[0]] >= need[s[0]]) {
            satisfied++;
        }
        while (l+r < s.size()) {
            if (satisfied == required) {
                if (r < min_len) {
                    min_len = r;
                    min_l = l;
                }
                int prev = char_freq[s[l]];
                char_freq[s[l]]--;
                if (need.contains(s[l])) {
                    if (prev == need[s[l]]) {
                        satisfied--;
                    }
                }   
                l++;
                r--;
            } else {
                r++;
                if (l+r < s.size()) {
                    int prev = char_freq[s[l+r]];
                    char_freq[s[l+r]]++;
                    if (need.contains(s[l+r])) {
                        if (prev == need[s[l+r]] - 1) {
                            satisfied++;
                        }
                    }   
                }
            }
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(min_l, min_len+1);
    }
};
