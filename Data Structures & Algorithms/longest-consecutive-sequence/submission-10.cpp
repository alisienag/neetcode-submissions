class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> appears;
        for (int n : nums) {
            appears.insert(n);
        }
        int max_consecutive = 0;
        for (const auto& num : appears) {

            if (!appears.contains(num-1)) {
                int j = 0;
                while (appears.contains(num + j)) {
                    j++;
                }
                if (j > max_consecutive) {
                    max_consecutive = j;
                }
            }
        }
        return max_consecutive;
    }
};
