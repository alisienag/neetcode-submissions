class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        if (l != r) {
            std::cout << "could not find min" << std::endl;
            return -1;
        }

        int min_idx = l;
        int target1 = binarySearch(nums, 0, min_idx-1, target);
        if (target1 != -1) {
            return target1;
        } else {
            return binarySearch(nums, min_idx, nums.size()-1, target);
        }
    }
};
