class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int s_size = s.size();
        int t_size = t.size();

        int s_p = 0 , t_p = 0;

        while(s_p < s_size && t_p < t_size ) {

            if (s[s_p] == t[t_p]){
                s_p++;
                t_p++;
            }
            else{
                t_p++;
            }
        }

        //cout << "s_p" << s_p << endl;
        //cout << "t_p" << t_p << endl;

        if (s_p == s_size)
            return true;
        return false;
    }
};
