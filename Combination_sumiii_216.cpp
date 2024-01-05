class Solution {

    void FillCombinations(int sum , int total_length , vector<int> combination , vector<vector<int>> &result) {

        if (combination.size() == total_length ) {
            int total_sum = 0;
            for (auto element : combination) {
                total_sum += element;
            }
            if (sum == total_sum)
            result.push_back(combination);
            return;
        }

        int start_p = 1 ;
        if (!combination.empty())
            start_p = combination.back() + 1;
        
        for (int i = start_p ; i <= 9 ; i++) {
            combination.push_back(i);
            FillCombinations(sum , total_length , combination , result);
            combination.pop_back();

        }

    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> combination;

        FillCombinations(n , k , combination , result);
        return result;
    

    }
};
