class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product = 1;
        std::vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }
        std::vector<int> postfix(nums.size());
        postfix[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i > 0; i--) {
            postfix[i] = postfix[i+1] * nums[i];
        }
        std::vector<int> result(nums.size());
        for (int i = 0; i < result.size(); i++) {
            int pre = 1;
            int post = 1;
            if (i - 1 >= 0) {
                pre = prefix[i-1];
            }
            if (i + 1 < postfix.size()) {
                post = postfix[i+1];
            }
            result[i] = post * pre;
        }
        return result;
    }
};
