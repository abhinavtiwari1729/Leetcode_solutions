class Solution {

    int solveRecur(vector<vector <int>> &obstacle , int curr_m , int curr_n , vector<vector<int>> &dp){
        
        if(curr_m == 0 and curr_n == 0)
            return 1;
        
        if(curr_m < 0 || curr_n < 0 || obstacle[curr_m][curr_n] == 1)
            return 0;


        if(dp[curr_m][curr_n] != -1)
            return dp[curr_m][curr_n];
        
        return dp[curr_m][curr_n] = solveRecur(obstacle , curr_m-1 , curr_n , dp) + solveRecur(obstacle , curr_m , curr_n-1 , dp);

    }


public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solveRecur(obstacleGrid , m-1 , n-1 , dp);                      

    }
};
