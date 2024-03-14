class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0 , n = nums.size();

        sort(nums.begin() , nums.end());

        for(int i = n-1 ; i >= 0 ; i--){

            int lo = 0 , hi = i-1;

            while(lo < hi){

                if(nums[lo] + nums[hi] > nums[i]){

                    result += hi - lo;
                    hi--;

                }

                else
                    lo++;
            }
        }

        return result;
    }
};
