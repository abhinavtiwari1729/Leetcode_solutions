class Solution {

    bool RegularExpressionMatch(string &s , string &p , int s_p , int p_p) {

        if(s_p < 0 && p_p < 0)
            return true;
        if(p_p < 0 && s_p >= 0)
            return false;
        
        if(s_p < 0 && p[p_p] == '*')
            return RegularExpressionMatch(s, p , s_p , p_p-2);

        if(s_p < 0 || p_p < 0)
            return false; 

        if(s[s_p] == p[p_p] || p[p_p] == '.')
            return RegularExpressionMatch(s , p , s_p-1 , p_p-1);
        
        if(p[p_p] == '*'){
            bool a = RegularExpressionMatch(s , p , s_p , p_p-2);
            bool b = false;
            if (p[p_p-1] == '.'){
                b = RegularExpressionMatch(s , p , s_p-1 , p_p);
            }
            else {
             if(p[p_p-1] == s[s_p])
                b = RegularExpressionMatch(s , p , s_p -1 , p_p);   
            }
            return a || b ;
        }

        return false;


    }

public:
    bool isMatch(string s, string p) {
        
        return RegularExpressionMatch(s, p , s.size()-1 , p.size()-1);

    }
};
