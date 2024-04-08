class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
    vector<int> result;

    for(int &ele : nums){

        int index = abs(ele);
        cout << index << endl;
        if(nums[index-1] < 0)
            result.push_back(index);
            
        nums[index-1] = -nums[index-1];
    }

    return result;

    }
};
