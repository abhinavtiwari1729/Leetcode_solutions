class Solution {

    int solveRecur(int index , int can_buy , vector<int> &prices , vector<vector<int>> &dp) {

        if(index >= prices.size())
            return 0;
        
        if(dp[index][can_buy] != -1)
            return dp[index][can_buy];
        int max_profit = 0;
        if(can_buy){

            int buy_profit = -prices[index] + solveRecur(index+1 , 0 , prices , dp);
            int not_buy_profit = solveRecur(index+1 , 1 , prices, dp);
            max_profit = max(buy_profit , not_buy_profit);
        }
        else{

            int sell_profit = prices[index] + solveRecur(index+1 , 1 , prices , dp);
            int not_sell_profit = solveRecur(index+1 , 0 , prices , dp);
            max_profit = max(sell_profit , not_sell_profit);

        }
        return dp[index][can_buy] = max_profit;
    }

public:
    int maxProfit(vector<int>& prices) {
         
        bool can_buy = true;
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return solveRecur(0 , 1 , prices , dp);
    }
};
