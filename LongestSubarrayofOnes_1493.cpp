class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int left = 0 ;
        int zeroes = 0 ;
        int ans = 0 ;

        for(int right = 0 ; right < n ; right++) {

            if(nums[right] == 0)
                zeroes++;

            while(zeroes > 1){
                if(nums[left] == 0)
                    zeroes--;
                
                left++;
            }

            ans = max(ans , right - left + 1 -zeroes);


        }

        return (ans == n ) ? ans-1 : ans;
    }
};
