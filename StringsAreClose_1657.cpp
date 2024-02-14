class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> v1(26,0) , v2(26,0);
        set<char> s1 , s2 ;

        for(char ch : word1){
            v1[ch-'a']++;
            s1.insert(ch);
        }

        for(char ch : word2){
            v2[ch-'a']++;
            s2.insert(ch);
        }

        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());

        if(v1 == v2 && s1 == s2)
            return true;
            
        return false;
    }
};
