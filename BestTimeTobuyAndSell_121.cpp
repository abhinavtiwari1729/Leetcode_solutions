class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int size = prices.size();
        if (size == 0 || size == 1)
            return 0;
        int max = prices[size-1];
        int max_profit = 0;
        int profit = 0;
        
        for (int i = size-2  ; i > -1 ; i--) {
            int item = prices[i];
            if(item > max)
                max = item;
            profit = max - item ; 
            
            if (profit > max_profit )
                max_profit = profit;
        }
        
        return max_profit;
    }
};
