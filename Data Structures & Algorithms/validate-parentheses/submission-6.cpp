class Solution {
public:
    bool isValid(string s) {
        std::vector<char> vec;
        vec.reserve(s.size());
        for (char c : s) {
            switch(c) {
                case '[':
                case '(':
                case '{':
                    vec.push_back(c);
                    break;
                case ']': {
                    if (vec.empty() || vec.back() != '[') {
                        return false;
                    }
                    vec.pop_back();
                    break;
                }
                case ')': {
                    if (vec.empty() || vec.back() != '(') {
                        return false;
                    }
                    vec.pop_back();
                    break;
                }
                case '}': {
                    if (vec.empty() || vec.back() != '{') {
                        return false;
                    }
                    vec.pop_back();
                    break;
                }
                default: return false;
            }
        }

        return vec.empty();
    }
};
