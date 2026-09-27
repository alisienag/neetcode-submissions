class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int longest = 1;
        std::unordered_map<char, int> seen;
        int fp = 0;
        int lp = 1;
        seen[s[fp]] = fp;
        while (fp+lp < s.size()) {
            if (seen.contains(s[fp+lp])) {
                int first_idx = seen[s[fp+lp]];
                if (first_idx >= fp) {
                    int current_idx = fp+lp;
                    fp = first_idx+1;
                    lp = current_idx - fp;
                    continue;
                }
            }
            seen[s[fp+lp]] = fp+lp;
            lp++;
            if (lp > longest) {
                longest = lp;
            }
        }
        
        return longest;
    }
};
