class Solution {

    bool validPalindromeUtil(string &s, int start , int end , bool fail_try) {

        if (start >= end)
            return true;
        
        bool match_character = (s[start] == s[end]);
        if (match_character){
            return validPalindromeUtil(s , start+1 , end-1 , fail_try);
        }
        else {
            if (fail_try == false){
                fail_try = true;
                return validPalindromeUtil(s , start , end-1 , fail_try) || validPalindromeUtil(s , start+1 , end , fail_try);
            }
            else
                return false;
        }




    }


public:
    bool validPalindrome(string s) {
        
        int end = s.size() -1 ;
        int start = 0;
        bool fail_try = false; 
        return validPalindromeUtil(s , start , end , fail_try);
    }
};
