class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;
        
        vector<int> count1(26 , 0);
        vector<int> count2(26 , 0);


        for(int i = 0 ; i < s1.size() ; i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if(count1 == count2)
            return true;
        
        int i = 0;
        int j = s1.size();

        int k = s2.size()-1;

        while(j <= k) {

            // removing start charcter 
            count2[s2[i] - 'a']--;

            // adding end charcter
            count2[s2[j] - 'a']++;

            if(count1 == count2)
                return true;
            
            i++;
            j++;
        }
    
        return false;
    }
};
