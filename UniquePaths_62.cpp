class Solution {

    void uniquePathSolve(int curr_m , int curr_n , int m , int n , int &total_ways){

        if(curr_m == m-1 && curr_n == n-1){
            total_ways++;
            return ;
        }
            
        if(curr_m+1 < m)
            uniquePathSolve(curr_m+1 , curr_n , m , n , total_ways);
        
        if(curr_n+1 < n )
            uniquePathSolve(curr_m , curr_n+1 , m , n , total_ways);
         
        return ;
    }

    int uniquepathRecur(int curr_m , int curr_n , int m , int n){

        if(curr_m == m-1 && curr_n == n-1)
            return 1;

        int total_ways = 0;
        if(curr_m < m )
            total_ways += uniquepathRecur(curr_m+1 , curr_n , m , n);
        if(curr_n < n)
            total_ways += uniquepathRecur(curr_m , curr_n+1 , m , n);

        return total_ways;
    }

    int uniquepathMemoization(int curr_m , int curr_n , int m , int n , vector<vector<int>> &dp){

        if(curr_m >= m || curr_n >= n)
            return 0;

        if(curr_m == m-1 && curr_n == n-1)
            return 1;

        if(dp[curr_m][curr_n] != -1)
            return dp[curr_m][curr_n];

        return dp[curr_m][curr_n] = uniquepathMemoization(curr_m+1 , curr_n , m , n , dp)+
                                 uniquepathMemoization(curr_m , curr_n+1 , m , n , dp);
    }

public:
    int uniquePaths(int m, int n) {
        

        vector<vector<int>> dp( m , vector<int>(n , -1));
        
        return uniquepathMemoization(0 , 0 , m , n , dp);

        //return uniquepathRecur(0 , 0 , m , n , dp);
        // int total_ways = 0;
        // uniquePathSolve(0 , 0 , m , n , total_ways);
        // return total_ways;

    }
};
