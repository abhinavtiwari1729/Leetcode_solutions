class Solution {

    int jumpUtil(vector<int> &nums , vector<int> &dp , int pos){

        if(pos >= nums.size()-1)
            return 0 ;
        
        if(dp[pos] != 10001)
            return dp[pos];
        
        int steps = nums[pos];

        int mini = 10000;
        for (int i = 1 ; i <= steps ; i++){
            int nextpos = jumpUtil(nums , dp , pos+i);
            mini = min(mini , nextpos );
        }
        dp[pos] = 1+mini;
        return dp[pos];
    }

public:
    int jump(vector<int>& nums) {
          
       int pos = 0;
       vector<int> dp(nums.size() , 10001);
       return jumpUtil(nums , dp , pos);   
    }
};
