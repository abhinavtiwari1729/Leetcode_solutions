class Solution {

    bool RecursiveMatch(string & s , string & p , int s_p , int p_p) {

        if (s_p < 0 && p_p < 0)
            return true;
        
        if (p_p < 0 && s_p >= 0)
            return false;
        
        if (s_p < 0 && p_p >= 0) {
            for(int p_sp = p_p ; p_sp >= 0 ; p_sp--)
                if(p[p_sp] != '*')
                    return false;
            return true;
        }

        if (s[s_p] == p[p_p] || p[p_p] == '?')
            return RecursiveMatch(s , p , s_p-1 , p_p-1);
        
        if (p[p_p] == '*')
            return RecursiveMatch(s , p , s_p-1 , p_p) || RecursiveMatch(s , p , s_p , p_p-1);
        
        return false;



    }


public:
    bool isMatch(string s, string p) {

     return RecursiveMatch(s , p , s.size() - 1 , p.size() - 1);

    }
};
