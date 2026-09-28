class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0) {
            return 0;
        }
        int fp = 0;
        int idx = 0;
        std::unordered_map<char, int> char_freq;
        
        int largest = 0;
        int max = 0;
        int total = 0;
        while (fp+idx < s.size()) {
            max = 0;
            total = 0;
            for (const auto& pair : char_freq) {
                if (pair.second > max) {
                    max = pair.second;
                }
                total += pair.second;
            }
            if (total-max > k) {
                char_freq[s[fp]]--;
                fp++;
                idx--;
            } else if (total-max <= k) {
                if (idx > largest) {
                    largest = idx;
                }
                char_freq[s[fp+idx]]++;
                idx++;
            }
        }
        max = 0;
            total = 0;
            for (const auto& pair : char_freq) {
                if (pair.second > max) {
                    max = pair.second;
                }
                total += pair.second;
            }
        if (total-max <= k) {
            if (idx > largest) {
                largest = idx;
            }
        }
        return largest;
    }
};
