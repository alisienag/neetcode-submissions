class Solution {
public:
    int min(int x, int y) {
        return x <= y ? x : y;
    }
    int maxArea(vector<int>& heights) {
        int fp = 0;
        int lp = heights.size()-1;
        int maxArea = 0;
        while (fp < lp) {
            int currentArea = min(heights[fp], heights[lp]) * (lp-fp);
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }
            if (heights[fp] < heights[lp]) {
                fp++;
            } else {
                lp--;
            }
        }
        return maxArea;
    }
};
