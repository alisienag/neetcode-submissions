class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_number = 0;
        for (int n : nums) {
            if (n > max_number) {
                max_number = n;
            }
        }
        std::unordered_map<int, int> appears;
        for (int n : nums) {
            appears[n] = 1;
        }
        int max_consecutive = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (appears[nums[i]-1] == 0) {
                int j = 1;
                while (appears[nums[i]+j] == 1) {
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
