class Solution {

    int robRecursion(vector<int> &nums , int index , vector<int> &dp){
        if(index >= nums.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        //include the current house
        int include_house = nums[index] + robRecursion(nums , index+2 , dp);
        int exclude_house = robRecursion(nums , index+1 , dp);

        int result = max(include_house , exclude_house);
        dp[index] = result;
        return result;
    }

    int robTabulation(vector<int> &nums) {

        vector<int> dp(nums.size() , -1);

        dp[0] = nums[0];
        if(nums.size() == 1)
            return nums[0];
        
        dp[1] = max(nums[0] , nums[1]);

        for(int i = 2 ; i < nums.size() ; i++){

            int include_house = nums[i] + dp[i-2];
            int exclude_house = dp[i-1];

            dp[i] = max(include_house , exclude_house);

        }

        return dp[nums.size()-1];
    }


    int robTabulationOPtimized(vector<int> &nums) {

        if(nums.size() == 1)
            return nums[0];

        int prev1 = max(nums[0] , nums[1]);
        int prev2 = nums[0];

        for(int i = 2 ; i < nums.size() ; i++){

            int include_house = nums[i] + prev2;
            int exclude_house = prev1;

            int curr = max(include_house , exclude_house);

            prev2 = prev1 ;
            prev1 = curr;

        }

        return prev1;
    }




public:
    int rob(vector<int>& nums) {
        
        // vector<int> dp(nums.size()+1 , -1);
        // return robRecursion(nums , 0 , dp);

        //return robTabulation(nums);
        return robTabulationOPtimized(nums);
    }
};
