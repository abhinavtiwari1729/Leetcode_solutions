class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int goalpost = nums.size()-1;
        int curr_pos = nums.size()-2;

        while(curr_pos >= 0){
            if (curr_pos + nums[curr_pos] >= goalpost){
                goalpost = curr_pos;
            }
            curr_pos--;
        }

        if(goalpost == 0)
            return true;
        
        return false;

    }
};
