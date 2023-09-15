// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int cmin = INT_MAX;

        for(int i=0; i<prices.size(); i++) {
            cmin = min(prices[i], cmin);
            result = max(result, prices[i] - cmin);
            /*if(prices[i] < min) {
                min = prices[i];
            } else {
                result = max(result, prices[i]- min);
            }*/
        }
 
        return result;
    }
};
