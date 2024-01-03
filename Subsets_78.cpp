class Solution {

    void solve(vector<int> nums , vector<int> output , int i , vector<vector <int>> & result) {

        if (i >= nums.size()){
            result.push_back(output);
            return ;
        }

        solve(nums , output , i+1 , result);

        output.push_back(nums[i]);

        solve(nums , output , i+1 , result);
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> output;
        int index = 0;
        solve(nums , output , index , result);
        return result;
    }
};
