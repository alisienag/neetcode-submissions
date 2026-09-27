class Solution {
public:

    string encode(vector<string>& strs) {
        std::stringstream ss;
        for (const auto& str : strs) {
            ss << "|" << str.size() << "|" << str;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        std::vector<string> result;
        for (int i = 0; i < s.size(); i++) {
            int size = 0;
            if (s[i] == '|') {
                i++;
                while (s[i] != '|') {
                    size *= 10;
                    size += s[i] - '0';
                    i++;
                }
                string res = s.substr(i+1, size);
                result.push_back(res);
                i += size;
            }
        }
        return result;
    }
};
