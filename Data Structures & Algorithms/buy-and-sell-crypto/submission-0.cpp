class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fp = 0;
        int lp = prices.size() - 1;
        int max_profit = 0;
        int lowest_previous = 100;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - lowest_previous > max_profit) {
                max_profit = prices[i] - lowest_previous;
            }
            if (lowest_previous > prices[i]) {
                lowest_previous = prices[i];
            }
        }
        return max_profit;
    }
};
