class Solution {

    int SolveRecur(string &text1 , string &text2 , int n , int m , vector<vector<int>> &dp) {

        if(  n < 0 || m < 0)
            return 0 ;
        
        if(dp[n][m] != -1)
            return dp[n][m];

        int include_one = 0;
        if(text1[n] == text2[m])
            include_one = 1 + SolveRecur(text1 , text2 , n-1 , m-1 , dp);
        
        int dec_n = SolveRecur(text1 , text2 , n-1 , m , dp);
        int dec_m = SolveRecur(text1 , text2 , n , m-1 , dp);

        return dp[n][m] = max(include_one , max(dec_n , dec_m));

    }

public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        return SolveRecur(text1 , text2 , n-1 , m-1 , dp);   
    }
};
