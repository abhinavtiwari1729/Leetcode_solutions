class Solution {

    int partition(vector<int> &nums , int left , int right , int pivot_index){

        int pivot = nums[pivot_index];
        swap(nums[pivot_index] , nums[right]);

        int limit_index = left;

        for(int i = left ; i < right ; i++){

            if(nums[i] < pivot){
                swap(nums[i] , nums[limit_index]);
                limit_index++;
            }

        }

        swap(nums[limit_index] , nums[right]);
        return limit_index;
    }


public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int left = 0 , right = nums.size()-1;
        while(true){

            int pivot_index = rand() % (right - left + 1) + left;
            int new_pivot_index = partition(nums , left , right , pivot_index);
            if(new_pivot_index == nums.size()-k)
                return nums[new_pivot_index];
            else if (new_pivot_index > nums.size()-k)
                right = new_pivot_index -1;
            else
                left = new_pivot_index + 1;

        }

    }
};
