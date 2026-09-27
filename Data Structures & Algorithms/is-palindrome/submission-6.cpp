class Solution {
public:
    bool isAlphaNum(char s) {
        if (s >= 'a' && s <= 'z') {
            return true;
        }
        if (s >= 'A' && s <= 'Z') {
            return true;
        }
        if (s >= '0' && s <= '9') {
            return true;
        }
        return s >= 'a' && s <= 'z' ? true : s >='A' && s <= 'Z' ? true : s >= '0' && s <= '9';
    }

    char toLowerCase(char s) {
        if (s >= 'a' && s <= 'z') {
            return s;
        }
        if (s >= 'A' && s <= 'Z') {
            return s - ('A' - 'a');
        }
        return s;
    }
    bool isPalindrome(string s) {


        std::string str;
        str.reserve(s.size());

        for (char c : s) {
            if (isAlphaNum(c)) {
                str += toLowerCase(c);
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
