class Solution {
public:
    int min(vector<int>& nums, int start, int end) {
        if (end - start == 1) {
            return nums[start];
        }
        if (end - start == 2) {
            return nums[start] > nums[start+1] ? nums[start+1] : nums[start];
        }

        int midPoint = start + (end - start)/2;

        int first = min(nums, start, midPoint);
        int second = min(nums, midPoint, end);
        if (first > second) {
            return second;
        } else {
            return first;
        }
    }
    int findMin(vector<int> &nums) {
        return min(nums, 0, nums.size());
    }
};
