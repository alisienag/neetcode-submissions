class Solution {
public:
    bool isPalindrome(string s) {
        std::string str;
        str.reserve(s.size());

        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }

        int start = 0;
        int end = str.size()-1;

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
