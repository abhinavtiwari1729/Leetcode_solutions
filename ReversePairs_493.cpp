class Solution {


    void _merge(vector<int> & nums , int start , int mid , int end , int & inversion) {

        int size = end - start + 1;
        vector<int> temp(size);

        int b = mid+1 ;
        for(int a = start ; a <= mid ; a++) {
            while((b <= end) && (long(nums[a]) > 2*long(nums[b]))) {
                    b++;
                }
            
            inversion = inversion + (b - (mid+1));
        }


        int i = start ;
        int j = mid + 1;
        int k = 0 ;
        while(i <= mid && j <= end) {
            
            if (nums[i] <nums[j]){
                temp[k] = nums[i];
                k++;
                i++;
            }
            else {
                temp[k] = nums[j];
                k++;
                j++;
            }

        }

        while(i <= mid){
            temp[k] = nums[i];
            k++ ;
            i++;
        }
        while(j <= end) {
            temp[k] = nums[j];
            k++;
            j++;
        }

        int l = 0 ;
        for(int number : temp){
            nums[start+l] = number;
            l++;
        }


    }




    void MergeSort(vector<int> & nums , int start , int end ,int &inversion) {

        if (start >= end)
            return ;
        int mid = start + (end - start)/2;

        MergeSort(nums , start , mid , inversion);
        MergeSort(nums , mid+1 , end , inversion);
        _merge(nums , start , mid , end , inversion);

    }

public:
    int reversePairs(vector<int>& nums) {
        int end = nums.size() -1 ;
        int start = 0 ;
        int inversion = 0 ;

        MergeSort(nums , start , end , inversion);
        return inversion;
    }
};
