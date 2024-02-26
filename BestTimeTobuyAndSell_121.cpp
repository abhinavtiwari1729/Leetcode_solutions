class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min = prices[0];
        int max_profit = 0;

        for(int i = 1 ; i < prices.size() ; i++){

            int profit = prices[i] - min ;
            max_profit = max(max_profit , profit);

            min = std::min(min , prices[i]);

        }

        return max_profit;
    }
};
