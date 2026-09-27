class Solution {
public:
    void quicksort_helper(vector<int>& vec, int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot = vec[start + (end-start)/2];
        int lt = start;
        int gt = end;

        while (lt <= gt) {
            while (vec[lt] < pivot) {
                lt++;
            }

            while (vec[gt] > pivot) {
                gt--;
            }

            if (lt > gt) {
                break;
            }

            int temp = vec[lt];
            vec[lt] = vec[gt];
            vec[gt] = temp;

            lt++;
            gt--;

        }
        quicksort_helper(vec, start, gt);
        quicksort_helper(vec, lt, end);
    }
    void quicksort(vector<int>& vec) {

        if (vec.size() <= 1) {
            return;
        }
        quicksort_helper(vec, 0, vec.size()-1);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        quicksort(nums);
        std::vector<std::vector<int>> results;

        for (int i = 0; i < nums.size() -2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int fp = i+1;
            int lp = nums.size() - 1;
            while (fp < lp) {
                int sum = nums[i] + nums[fp] + nums[lp];
                if (sum > 0) {
                    lp--;
                }
                if (sum < 0) {
                    fp++;
                }
                if (sum == 0) {
                    results.push_back({nums[i], nums[fp], nums[lp]});
                    while(lp - 1 >=0 && nums[lp] == nums[lp-1]) {
                        lp--;
                    }
                    lp--;
                }
            }
        }
        
        
        return results;
    }
};
