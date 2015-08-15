class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() == 0)
            return ans;
        int min_price = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            ans = max(ans, prices[i]-min_price);
            min_price = min(prices[i], min_price);
        }
        return ans;
    }
};