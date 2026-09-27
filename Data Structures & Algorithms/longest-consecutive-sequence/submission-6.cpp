class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> appears;
        for (int n : nums) {
            appears[n] = 1;
        }
        int max_consecutive = 0;
        for (const auto& pair : appears) {
            int num = pair.first;

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
