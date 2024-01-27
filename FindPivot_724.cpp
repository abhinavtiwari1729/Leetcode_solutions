class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int size = nums.size();
        if (size == 1)
            return 0 ;

        int sum = 0;
        vector<int> prefixSum(size) ;
        for(int i = 0 ; i < size ; i++) {
            sum += nums[i];
            prefixSum[i] = sum ;
        }    

        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0 ; i < size ;  i++){
            leftSum = (i == 0) ? 0 : prefixSum[i-1];
            rightSum = (i == size-1) ? 0 : prefixSum[size-1] - prefixSum[i];
            if(leftSum == rightSum)
                return i; 
        }

        return -1;

    
    }
};
