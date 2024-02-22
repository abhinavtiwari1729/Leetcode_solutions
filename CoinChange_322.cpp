class Solution {

    int solveRecur1(vector<int>& coins , int amount , vector<int> &dp){
        if (amount == 0)
            return 0;
        
        if (amount < 0)
            return 10001;
        
        if(dp[amount] != -1)
            return dp[amount];

        int min_result = 10001;

        for(int i = 0 ; i < coins.size() ; i++){

            min_result = min(min_result , solveRecur1(coins , amount - coins[i] , dp) + 1 );
        }
        
        dp[amount] = min_result;

        return min_result;

    }


    int solveTabulation(vector<int> &coins , int amount){

        vector<int> dp(amount+1 , 10001);

        dp[0] = 0;

        for(int i = 1 ; i <= amount ; i++){
            
            for(int j = 0 ; j < coins.size() ; j++){

                if(i-coins[j] >= 0 && i-coins[j] != 10001)
                dp[i] =  min(dp[i] , dp[i-coins[j]]+1);
            }
        }

        if(dp[amount] == 10001)
            return -1;

        return dp[amount];

    }


public:
    int coinChange(vector<int>& coins, int amount) {
        
        // vector<int> dp(amount+1 , -1);
        // int result = solveRecur1(coins , amount , dp);

        // if(result == 10001)
        //     return -1;
        
        // return result;

        return solveTabulation(coins , amount);

    }
};
