class Solution {

    //recursive solution
    int solve(vector<int> &cost , int index) {

        if(index == 0 || index == 1)
            return cost[index];
        
        return min(solve(cost , index-1) , solve(cost , index-2)) + cost[index]; 

    }

    // Dp solution top-down approach with memoization and recursion
    int solve2(vector<int> &cost , vector<int> &dp , int index){

        if(index == 0 || index == 1)
            return cost[index];

        if(dp[index] != -1)
            return dp[index];

        dp[index] = min(solve2(cost ,dp,index-1) , solve2(cost ,dp ,index-2)) + cost[index];
        return dp[index];

    }


    // DP soultion bottom-up approach with tabulation
    int solve3(vector<int> &cost) {

        int n = cost.size();
        vector<int> dp(n , -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2 ; i < n ; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }


        return min(dp[n-1] , dp[n-2]);

    }



public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        //vector<int> dp(n , -1);
        //return min(solve2(cost , dp ,  n-1) , solve2(cost , dp , n-2));
        return solve3(cost);
    }
};
