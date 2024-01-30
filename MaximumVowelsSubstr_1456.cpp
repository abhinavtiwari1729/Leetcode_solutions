class Solution {

    bool IsVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        
        return false;
    }
public:
    int maxVowels(string s, int k) {
        
        int maxi = 0;
        for (int i  = 0 ; i < k ; i++){
            if(IsVowel(s[i]))
                maxi++;
        }
        if (maxi == k )
            return k ;
        int w_s = 0 ;
        int w_e = k ;
        int w_max = maxi;

        while(w_e < s.size()){
            if (IsVowel(s[w_s]))
                w_max--;
            if(IsVowel(s[w_e]))
                w_max++;
            
            maxi = max(maxi , w_max); 
            if(maxi == k)
                return k ;

            w_s++;
            w_e++;
        }

        return maxi;
    }
};
