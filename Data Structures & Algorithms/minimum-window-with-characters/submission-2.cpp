class Solution {
public:
    bool isValid(std::unordered_map<char, int>& char_freq,
        std::unordered_map<char, int>& need) {
        for (const auto& pair : need) {
            if (!char_freq.contains(pair.first)) {
                return false;
            } else if (char_freq[pair.first] < pair.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        std::unordered_map<char, int> char_freq;
        std::unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }
        int min_l = INT_MAX;
        int min_len = INT_MAX;
        int l = 0;
        int r = 0;
        char_freq[s[0]]++;
        while (l+r < s.size()) {
            if (isValid(char_freq, need)) {
                if (r < min_len) {
                    min_len = r;
                    min_l = l;
                }
                char_freq[s[l]]--;
                l++;
                r--;
            } else {
                r++;
                if (l+r < s.size()) {
                    char_freq[s[l+r]]++;
                }
            }
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(min_l, min_len+1);
    }
};
